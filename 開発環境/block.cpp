//==================================
//�����b �A�N�V����(block.cpp)
//	Author:�@��q����
//==================================
#include"block.h"
//�}�N����`
#define MAX_BLOCK		(128)					//�u���b�N�̍ő吔

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureBlock[MAX_BLOCK] = {};			//�e�N�X�`���ւ̃|�C���^								//���_���̊i�[
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffBlock = NULL;	//���_�o�b�t�@�ւ̃|�C���^
BLOCK g_aBlock[MAX_BLOCK];						//�u���b�N�̏��

//�u���b�N�̏���������
void InitBlock(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/block001.jpg", &g_pTextureBlock[0]);

	//�u���b�N�̏��̏�����
	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		g_aBlock[nCntBlock].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlock[nCntBlock].bUse = false;
		g_aBlock[nCntBlock].fWidth = 1000.0f;
		g_aBlock[nCntBlock].fHeight = 40.0f;
	}
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 44 * MAX_BLOCK,
		D3DUSAGE_WRITEONLY, FVF_VERTEX_2D,
		D3DPOOL_MANAGED, &g_pVtxBuffBlock, NULL);

	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffBlock->Lock(0, 0, (void**)&pVtx, 0);
		
	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(40.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(40.0f, 1.0f);
		pVtx += 4;			//���_�f�[�^�̃|�C���^��4���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffBlock->Unlock();

	SetBlock(D3DXVECTOR3(-150.0f, 400.0f, 0.0f), 5, 1);		//��
	SetBlock(D3DXVECTOR3(1400.0f, 400.0f, 0.0f), 1, 1);		//�E
	SetBlock(D3DXVECTOR3(800.0f, 700.0f, 0.0f), 4, 40);		//��1
	SetBlock(D3DXVECTOR3(20.0f, 700.0f, 0.0f), 4, 40);		//��2
	SetBlock(D3DXVECTOR3(800.0f, 0.0f, 0.0f), 4, 40);		//��1
	SetBlock(D3DXVECTOR3(20.0f, 0.0f, 0.0f), 4, 40);		//��2
}

//�u���b�N�̏I������
void UninitBlock(void)
{
	//�e�N�X�`���̔j��
	
		if (g_pTextureBlock[0] != NULL)
		{
			g_pTextureBlock[0]->Release();
			g_pTextureBlock[0] = NULL;
		}
	
	//���_�o�b�t�@�̔j��
	
		if (g_pVtxBuffBlock != NULL)
		{
			g_pVtxBuffBlock->Release();
			g_pVtxBuffBlock = NULL;
		}
}

//�u���b�N�̍X�V����
void UpdateBlock(void)
{

}

//�u���b�N�̕`�揈��
void DrawBlock(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�ւ̃|�C���^
	
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffBlock, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		if (g_aBlock[nCntBlock].bUse == true)
		{//�u���b�N���g�p����Ă���Ƃ�
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureBlock[0]);
			//�|���S���`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
				nCntBlock * 4,//�`�悷��摜�̍ŏ��̒��_�C���f�b�N�X
				2);	//�|���S����
		}                                                        
	}
}

//�u���b�N�̐ݒ菈��
void SetBlock(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;

	//���_�������b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffBlock->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		if (g_aBlock[nCntBlock].bUse == false)
		{
			g_aBlock[nCntBlock].pos = pos;

			//���_���W�X�V
			pVtx[0].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2, 0.0f);
			g_aBlock[nCntBlock].bUse = true;
			break;
		}
		//���_�f�[�^�̃|�C���^��4���i�߂�
		pVtx += 4;
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffBlock->Unlock();
}


//�����蔻��i�u���b�N�j
bool CollisionBlock(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pPosOld,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight)
{
	bool bIsLanding = false;
	for(int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{ 
		if (g_aBlock[nCntBlock].bUse == true)
		{
			if (//����i��j
				(g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) >= pPosOld->y
				&& (g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) < pPos->y
				&& (g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) > (pPos->x - fWidith/2)
				&&(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) < (pPos->x + fWidith/2))
			{
				bIsLanding = true;	//���n���Ă���
				pPos->y = g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2;
				pMove->y = 0.0f;
			}
			 if (//����(��)
				(g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) <= pPosOld->y - PLAYER_SIZE_Y
				&& (g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) > pPos->y - PLAYER_SIZE_Y
				&& (g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) > (pPos->x - fWidith/2)
				&& (g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) < (pPos->x + fWidith/2))
			{
				
				pPos->y = g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2 + PLAYER_SIZE_Y;
				pMove->y = 0.0f;
			}
			if(//����(��)
				(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) >= pPosOld->x + PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) < pPos->x + PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) > (pPos->y - fHeight/2) 
				&& (g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) < pPos->y )
			{
				
				pPos->x = g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2 - PLAYER_SIZE_X/2;
				pMove->x= 0.0f;
			}
		 if (//����(�E)
				(g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) <= pPosOld->x - PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) > pPos->x - PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) > (pPos->y - fHeight/2) 
				&& (g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) < pPos->y )
			{

				pPos->x = g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2 + PLAYER_SIZE_X/2;
				pMove->x = 0.0f;
			}
		}
	}
	return bIsLanding;
}
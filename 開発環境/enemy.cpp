//==================================
//�����b �A�N�V����(enemy.cpp)
//	Author:�@��q����
//==================================
#include"enemy.h"

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureEnemy[NUM_ENEMY] = {};			//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffEnemy = NULL;				//���_�o�b�t�@�ւ̃|�C���^
Enemy g_aEnemy[MAX_ENEMY];									//�G�̏��

//�G�̏���������
void InitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEnemy;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/purin.png", &g_pTextureEnemy[0]);
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/jelly.png", &g_pTextureEnemy[1]);
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/�v�����A�����[�h.png", &g_pTextureEnemy[2]);
	
	//�G�̏��̏�����
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		g_aEnemy[nCntEnemy].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].nType = 0;
		//g_aEnemy[nCntEnemy].nLife = 10;
		g_aEnemy[nCntEnemy].fWidth = 50;
		g_aEnemy[nCntEnemy].fHeight = 50;
		g_aEnemy[nCntEnemy].bUse = false;
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ENEMY,
		D3DUSAGE_WRITEONLY, FVF_VERTEX_2D,
		D3DPOOL_MANAGED, &g_pVtxBuffEnemy, NULL);
	VERTEX_2D*pVtx;	//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
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
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;			//���_�f�[�^�̃|�C���^��4���i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffEnemy->Unlock();

	SetEnemy(D3DXVECTOR3(555.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(55.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(1100.0f, 680.0f, 0.0f), 1);
	SetEnemy(D3DXVECTOR3(900.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(1270.0f, 380.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(200.0f, 380.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(10.0f, 380.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(1111.0f, 380.0f, 0.0f), 1);
	SetEnemy(D3DXVECTOR3(300.0f, 680.0f, 0.0f), 1);
	SetEnemy(D3DXVECTOR3(700.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(550.0f, 100.0f, 0.0f), 0);
}

//�G�̏I������
void UninitEnemy(void)
{
	//�T�E���h�̒�~
	StopSound();

	//�e�N�X�`���̔j��
	for (int nCntEnemy = 0; nCntEnemy<NUM_ENEMY; nCntEnemy++)
	{ 
		if (g_pTextureEnemy[nCntEnemy] != NULL)
		{
			g_pTextureEnemy[nCntEnemy]->Release();
			g_pTextureEnemy[nCntEnemy] = NULL;
		}

	}

	//���_�o�b�t�@�̔j��
		if (g_pVtxBuffEnemy != NULL)
		{
			g_pVtxBuffEnemy->Release();
			g_pVtxBuffEnemy = NULL;
		}
}

//�G�̍X�V����
void UpdateEnemy(void)
{
	int nCntEnemy;
	VERTEX_2D * pVtx;
	//���_�������b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{//�e���g�p����Ă���
			switch(g_aEnemy[nCntEnemy].state)
			{
			case ENEMYSTATE_NORMAL:

				break;
			case ENEMYSTATE_DAMAGE:
				g_aEnemy[nCntEnemy].nCounterState--;
				if (g_aEnemy[nCntEnemy].nCounterState<=0)
				{
					g_aEnemy[nCntEnemy].state = ENEMYSTATE_NORMAL;
					//���_�J���[�̐ݒ�
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				break;
				
			}

			//���_���W�X�V
			pVtx[0].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE_Y, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE_Y, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y , 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y , 0.0f);

		}
		pVtx += 4;			//���_�f�[�^�̃|�C���^��4���i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffEnemy->Unlock();
}

//�G�̕`�揈��
void DrawEnemy(void)
{
	
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�ւ̃|�C���^
	int nCntEnemy;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffEnemy, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{	//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureEnemy[g_aEnemy[nCntEnemy].nType]);
			//�G�̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	nCntEnemy * 4,2);	
		}
	}
}
//�G�̐ݒ菈��
void SetEnemy(D3DXVECTOR3 pos, int nType)
{
	int nCntEnemy;

	VERTEX_2D * pVtx;

	//���_�������b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == false)
		{//�G���g�p����Ă��Ȃ��ꍇ

			g_aEnemy[nCntEnemy].pos = pos;
			g_aEnemy[nCntEnemy].nType = nType;
		/*	g_aEnemy[nCntEnemy].nLife = 10;*/
			g_aEnemy[nCntEnemy].bUse = true;

			break;
		}

		pVtx += 4;			//���_�f�[�^�̃|�C���^��4���i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffEnemy->Unlock();
}

//�G�̎擾
Enemy * GetEnemy(void)
{
	Enemy *pEnemy = g_aEnemy;

	//�Ԃ�l
	return pEnemy;
}

//�����蔻��i�G�j
void CollisionEnemy(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight)
{
	Enemy*pEnemy;
	pEnemy = GetEnemy();
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (pEnemy->bUse == true)
		{
			if (//����
				(g_aEnemy[nCntEnemy].pos.y - g_aEnemy[nCntEnemy].fHeight/2) <= pPos->y
				&& (g_aEnemy[nCntEnemy].pos.y + g_aEnemy[nCntEnemy].fHeight/2) >= pPos->y - PLAYER_SIZE_Y/2
				&& (g_aEnemy[nCntEnemy].pos.x - g_aEnemy[nCntEnemy].fWidth/2) <= pPos->x + PLAYER_SIZE_X / 2
				&& (g_aEnemy[nCntEnemy].pos.x + g_aEnemy[nCntEnemy].fWidth/2) >= pPos->x - PLAYER_SIZE_X / 2)
			{
				if (g_aEnemy[nCntEnemy].bUse == true)
				{
					if (g_aEnemy[nCntEnemy].nType == 0)
					{
						AddScore(+300);
						g_aEnemy[nCntEnemy].bUse = false;
					}
					else if (g_aEnemy[nCntEnemy].nType == 1)
					{
						AddScore(-500);
						g_aEnemy[nCntEnemy].bUse = false;
					}
					else if (g_aEnemy[nCntEnemy].nType == 2)
					{
						AddScore(+3000);
						g_aEnemy[nCntEnemy].bUse = false;
						//�T�E���h�̍Đ�
						PlaySound(SOUND_LABEL_SE_GET);
					}
					//�T�E���h�̍Đ�
					PlaySound(SOUND_LABEL_SE_GET2);
				}
			}
		}
		pEnemy++;
	}
}
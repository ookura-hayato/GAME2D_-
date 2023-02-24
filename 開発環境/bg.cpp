//==================================
//�����b �A�N�V����(bg.cpp)
//	Author:�@��q����
//==================================
#include"bg.h"



//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureBG = NULL;	//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBG = NULL;	//���_�o�b�t�@�ւ̃|�C���^
float g_aPosTexV;	//�e�N�X�`�����W�̊J�n�ʒu�iV�l�j

//�w�i�̏���������
void InitBg(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^


	pDevice = GetDevice();		//�f�o�C�X�̎擾

	D3DXCreateTextureFromFile(pDevice,"data/TEXTURE/bg105.png",&g_pTextureBG);

	//���_�o�b�t�@�̐ݒ�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,	//�m�ۂ���o�b�t�@�̃T�C�Y 
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,	//���_�t�H�[�}�b�g
		D3DPOOL_MANAGED,
		&g_pVtxBuffBG,
		NULL);

	VERTEX_2D *pVtx;	//���_���̃|�C���^

		//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
		g_pVtxBuffBG->Lock(0, 0, (void**)&pVtx, 0);

		//���_���W�ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		//���_�o�b�t�@���A�����b�N����
		g_pVtxBuffBG->Unlock();
	
}

void UninitBg(void)
{
	//�o�b�t�@�j��
	
		if (g_pVtxBuffBG != NULL)
		{
			g_pVtxBuffBG->Release();
			g_pVtxBuffBG = NULL;
		}
	
	//�e�N�X�`���j��
	if (g_pTextureBG != NULL)
		{
			g_pTextureBG->Release();
			g_pTextureBG = NULL;
		}
}

void UpdateBg(void)
{
	
}

void DrawBg(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();	//�f�o�C�X�̎擾

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffBG, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���ݒ�
	
		pDevice->SetTexture(0, g_pTextureBG);

	//�|���S���`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);	//�v���~�e�B�u�̎��
}
//==================================
//�����b �A�N�V����(timer.cpp)
//	Author:�@��q����
//==================================
#include "timer.h"

//�}�N����`
#define NUM_TIMER (3)											//�^�C�}�[�̌�

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureTimer = NULL;						//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTimer = NULL;					//���_�o�b�t�@�ւ̃|�C���^	
D3DXVECTOR3 g_posTimer;											//�^�C�}�[�̈ʒu
int g_nTimer;													//�^�C�}�[�̒l
int g_nFlemTimer;												//�^�C�}�[�̃t���[���̒l

//�^�C�}�[�̏���������
void InitTimer(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,"data/TEXTURE/number000.png",&g_pTextureTimer);

	g_posTimer = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//�ʒu��������
	g_nTimer = 35;												//�l��������
	g_nFlemTimer = 0;											//�l��������

	//���_�o�b�t�@�̍쐬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 *NUM_TIMER,
		D3DUSAGE_WRITEONLY,FVF_VERTEX_2D,D3DPOOL_MANAGED,&g_pVtxBuffTimer,NULL);

	VERTEX_2D*pVtx;		//���_���փ|�C���^

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffTimer->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntTimer = 0; nCntTimer < NUM_TIMER; nCntTimer++)
	{

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(550.0f + (50.0f * nCntTimer), 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(600.0f + (50.0f * nCntTimer), 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(550.0f + (50.0f * nCntTimer), 50.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(600.0f + (50.0f * nCntTimer), 50.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̕`��
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

		pVtx += 4;//�|�C���^���S���i�߂�
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffTimer->Unlock();
	
}

//�^�C�}�[�̏I������
void UninitTimer(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureTimer != NULL)
	{
		g_pTextureTimer->Release();
		g_pTextureTimer = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffTimer != NULL)
	{
		g_pVtxBuffTimer->Release();
		g_pVtxBuffTimer = NULL;
	}
}

//�^�C�}�[�̍X�V����
void UpdateTimer(void)
{
	if (g_nFlemTimer > 60)
	{
		if (g_nTimer != 0)
		{
			g_nTimer--;
			SetTimer(g_nTimer);
		}

		if (g_nTimer == 30)
		{
			SetEnemy(D3DXVECTOR3(753.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(831.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(526.0f, 680.0f, 0.0f), 1);   
			SetEnemy(D3DXVECTOR3(1907.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1010.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(800.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1315.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(101.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(564.0f, 680.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(634.0f, 380.0f, 0.0f), 0);
		}

		if (g_nTimer == 25)
		{
			SetEnemy(D3DXVECTOR3(109.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(929.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(777.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(56.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(398.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(373.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(410.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(1526.0f, 680.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(1878.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(200.0f, 680.0f, 0.0f), 1);
		}

		if (g_nTimer == 20)
		{
			SetEnemy(D3DXVECTOR3(1567.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(0.0f, 680.0f, 0.0f), 2);
			SetEnemy(D3DXVECTOR3(912.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(301.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1398.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(0.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1116.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(656.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1259.0f, 380.0f, 0.0f), 0);
		}

		if (g_nTimer == 15)
		{
			SetEnemy(D3DXVECTOR3(555.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(59.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(630.0f, 680.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(893.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(164.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1222.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(430.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(375.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(640.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1235.0f, 680.0f, 0.0f), 0);
		}

		if (g_nTimer == 10)
		{
			SetEnemy(D3DXVECTOR3(44.0f, 680.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(808.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(325.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(302.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(5.0f, 380.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(64.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(464.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(97.0f, 380.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(949.0f, 680.0f, 0.0f), 1);
			SetEnemy(D3DXVECTOR3(118.0f, 680.0f, 0.0f), 0);
		}

		if (g_nTimer == 5)
		{
			SetEnemy(D3DXVECTOR3(5.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(505.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1070.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(590.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1270.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(0.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(660.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(190.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(700.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(506.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(562.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(28.0f, 680.0f, 0.0f), 0);
			SetEnemy(D3DXVECTOR3(1128.0f, 680.0f, 0.0f), 0);
 			SetEnemy(D3DXVECTOR3(550.0f, 100.0f, 0.0f), 2);
		}

		g_nFlemTimer = 0;
	}
	g_nFlemTimer++;

	if (g_nTimer <= 0)
	{
	
		//���U���g��ʂɑJ��
		SetMode(MODE_RESULT);
	}

}

//�^�C�}�[�̕`�揈��
void DrawTimer(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffTimer, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureTimer);

	for (int nCntTimer = 0; nCntTimer < NUM_TIMER; nCntTimer++)
	{
		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntTimer * 4, 2);
	}
}

//�^�C�}�[�̐ݒ菈��
void SetTimer(int nTimer)
{
	int aPosTexU[NUM_TIMER];	//�e���̐������i�[

	g_nTimer = nTimer;

	aPosTexU[0] = g_nTimer % 1000 / 100;
	aPosTexU[1] = g_nTimer % 100 / 10;
	aPosTexU[2] = g_nTimer % 10 / 1;

	VERTEX_2D*pVtx;		//���_���փ|�C���^

	//���_�o�b�t�@�����b�N���A���_���փ|�C���^�擾
	g_pVtxBuffTimer->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntTimer = 0; nCntTimer < NUM_TIMER; nCntTimer++)
	{
		pVtx[0].tex = D3DXVECTOR2(0.1f * aPosTexU[nCntTimer], 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f * (aPosTexU[nCntTimer] + 1), 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.1f * aPosTexU[nCntTimer], 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f * (aPosTexU[nCntTimer] + 1), 1.0f);

		pVtx += 4;//�|�C���^���S���i�߂�
	}
	//���_�o�b�t�@�A�����b�N
	g_pVtxBuffTimer->Unlock();

}
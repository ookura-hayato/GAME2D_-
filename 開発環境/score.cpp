//==================================
//�����b �A�N�V����(score.cpp)
//	Author:�@��q����
//==================================
#include"score.h"
//�}�N����`
#define NUM_SCORE (8)

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureScore = NULL;			//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffScore = NULL;		//���_�o�b�t�@�ւ̃|�C���^
D3DXVECTOR3 g_posScore;								//�X�R�A�̈ʒu
int g_nScore;										//�X�R�A�̒l

//�X�R�A�̏���������
void InitScore(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();//�f�o�C�X�̎擾

  //�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,"data/TEXTURE/number000.png",&g_pTextureScore);

	g_posScore = D3DXVECTOR3(850.0f, 10.0f, 0.0f);	//�ʒu�̏�����
	g_nScore = 0;	//�l�̏�����

	//���_�o�b�t�@�̐ݒ�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4* NUM_SCORE,	//�m�ۂ���o�b�t�@�̃T�C�Y 
		D3DUSAGE_WRITEONLY,FVF_VERTEX_2D,D3DPOOL_MANAGED,&g_pVtxBuffScore,NULL);

	VERTEX_2D *pVtx;	//���_���̃|�C���^
	
	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffScore->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(g_posScore.x + (50.0f * nCntScore), g_posScore.y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_posScore.x + 50 + (50.0f * nCntScore), g_posScore.y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(g_posScore.x + (50.0f * nCntScore), g_posScore.y + 50.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_posScore.x  + 50+ (50.0f * nCntScore), g_posScore.y + 50.0f, 0.0f);

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
		pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

		pVtx += 4;

	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffScore->Unlock();
}

//�X�R�A�̏I������
void UninitScore(void)
{
	//�o�b�t�@�j��
	if (g_pVtxBuffScore != NULL)
	{
		g_pVtxBuffScore->Release();
		g_pVtxBuffScore = NULL;
	}

	//�e�N�X�`���j��
	if (g_pTextureScore != NULL)
	{
		g_pTextureScore->Release();
		g_pTextureScore = NULL;
	}
}

//�X�R�A�̍X�V����
void UpdateScore(void)
{

}

//�X�R�A�̕`�揈��
void DrawScore(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();	//�f�o�C�X�̎擾

							//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffScore, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureScore);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,4 * nCntScore,2);
	}
}

//�X�R�A�̐ݒ菈��
void SetScore(int nScore, D3DXVECTOR3 pos)
{
	VERTEX_2D *pVtx;
	float aPosTexU[NUM_SCORE];											//�e���̐��l���i�[
	int nCntScore;
	g_nScore = nScore;

	aPosTexU[0] = ((g_nScore % 100000000) / 10000000) * 0.1f;
	aPosTexU[1] = ((g_nScore % 10000000) / 1000000) * 0.1f;
	aPosTexU[2] = ((g_nScore % 1000000) / 100000) * 0.1f;
	aPosTexU[3] = ((g_nScore % 100000) / 10000) * 0.1f;
	aPosTexU[4] = ((g_nScore % 10000) / 1000) * 0.1f;
	aPosTexU[5] = ((g_nScore % 1000) / 100) * 0.1f;
	aPosTexU[6] = ((g_nScore % 100) / 10) * 0.1f;
	aPosTexU[7] =  (g_nScore % 10) * 0.1f;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffScore->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{
		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 1.0f);

		pVtx += 4;
	}
	//���_���W���A�����b�N
	g_pVtxBuffScore->Unlock();
}

//�X�R�A�̉��Z����
void AddScore(int nValue)
{
	VERTEX_2D *pVtx;
	float aPosTexU[NUM_SCORE];											//�e���̐��l���i�[
	g_nScore += nValue;

	aPosTexU[0] = ((g_nScore % 100000000) / 10000000) * 0.1f;
	aPosTexU[1] = ((g_nScore % 10000000) / 1000000) * 0.1f;
	aPosTexU[2] = ((g_nScore % 1000000) / 100000) * 0.1f;
	aPosTexU[3] = ((g_nScore % 100000) / 10000) * 0.1f;
	aPosTexU[4] = ((g_nScore % 10000) / 1000) * 0.1f;
	aPosTexU[5] = ((g_nScore % 1000) / 100) * 0.1f;
	aPosTexU[6] = ((g_nScore % 100) / 10) * 0.1f;
	aPosTexU[7] =  (g_nScore % 10) * 0.1f;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffScore->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{
		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 1.0f);

		pVtx += 4;
	}
	//���_���W���A�����b�N
	g_pVtxBuffScore->Unlock();
}

int GetScore(void)
{
	return g_nScore;
}
//==================================
//�����b �A�N�V����(player.cpp)
//	Author:�@��q����
//==================================
#include "player.h"

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTexturePlayer = NULL;			//�e�N�X�`���ւ̃|�C���^								//���_���̊i�[
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffPlayer = NULL;	//���_�o�b�t�@�ւ̃|�C���^
PLAYER g_Player;

//�v���C���[����������
void InitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,"data/TEXTURE/���C���[ 0.1.png",&g_pTexturePlayer);
	
	g_Player.pos = D3DXVECTOR3(450.0f, 550.0f, 0.0f);			//�ʒu��������
	g_Player.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�ړ��ʂ�������

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D,
		D3DPOOL_MANAGED, &g_pVtxBuffPlayer,NULL);
	VERTEX_2D*pVtx;										//���_���ւ̃|�C���^
	g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);		//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾

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
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.5f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.5f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffPlayer->Unlock();
}

//�v���C���[�̏I������
void UninitPlayer(void)
{
	//�e�N�X�`���̔j��
	if (g_pTexturePlayer != NULL)
	{
		g_pTexturePlayer->Release();
		g_pTexturePlayer = NULL;
	}
	
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffPlayer != NULL)
	{
		g_pVtxBuffPlayer->Release();
		g_pVtxBuffPlayer = NULL;
	}
}

//�v���C���[�̍X�V����
void UpdatePlayer(void)
{
	VERTEX_2D *pVtx;			//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);
	if (GetKeyboardPress(DIK_A) == true)
	{//A�L�[�������ꂽ
		//���ړ�
		
			g_Player.move.x = -5.0f;
			if (g_Player.move.x)
			{
				/*g_Player.nCounterAnim++;
				if (g_Player.nCounterAnim == 4)
				{
					g_Player.nPatternAnim = (g_Player.nPatternAnim + 1) % 20;*/
					pVtx[0].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 0.0f);
					pVtx[1].tex = D3DXVECTOR2((1.0f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 0.0f);
					pVtx[2].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 1.0f);
					pVtx[3].tex = D3DXVECTOR2((1.0f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 1.0f);
				//	if (g_Player.nPatternAnim == 0)//���p�^�[���𒴂���
				//	{
				//		g_Player.nPatternAnim = false;
				//	}
				//	g_Player.nCounterAnim = 0;
				//}
			}
	}

	if (GetKeyboardPress(DIK_D) == true)
	{//D�L�[�������ꂽ
	 //�E�ړ�
		
			g_Player.move.x = 5.0f;
			if (g_Player.move.x)
			{
				/*g_Player.nCounterAnim++;
				if (g_Player.nCounterAnim == 4)
				{
					g_Player.nPatternAnim = (g_Player.nPatternAnim + 1) % 20;*/
					pVtx[0].tex = D3DXVECTOR2((0.0f/* + g_Player.nPatternAnim*0.25f*/)*1 , 0.0f);
					pVtx[1].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/)*1, 0.0f);
					pVtx[2].tex = D3DXVECTOR2((0.0f /*+ g_Player.nPatternAnim*0.25f*/) *1, 1.0f);
					pVtx[3].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/) *1, 1.0f);
				//	if (g_Player.nPatternAnim == 0)//���p�^�[���𒴂���
				//	{
				//		g_Player.nPatternAnim = false;
				//	}
				//	g_Player.nCounterAnim = 0;
				//}
			}
	}

	if (GetKeyboardTrigger(DIK_SPACE) == true)
	{//SPACE�L�[�������ꂽ
		//�W�����v
		if(g_Player.bIsJamping ==false)
		{ 
			g_Player.bIsJamping = true;
			g_Player.move.y -= 30.0f;
		}
	}

	g_Player.move.y += 1.0f;		//�d�͉���
	//�O��̈ʒu��ۑ�
	g_Player.posOld = g_Player.pos;
	//��ʈړ�(���E)
	if (g_Player.pos.x + 50.0f < 0.0f)
	{
		g_Player.pos.x = SCREEN_WIDTH + 50.0f;
		g_Player.posOld.x = SCREEN_WIDTH + 50.0f;
	}

	else if (g_Player.pos.x - 50.0f > SCREEN_WIDTH)
	{
		g_Player.pos.x = -50.0f;
		g_Player.posOld.x = -50.0f;
	}

	//�ʒu���X�V
	g_Player.pos.x += g_Player.move.x;
	g_Player.pos.y += g_Player.move.y;

	//�ړ��ʍX�V�i�����j
	g_Player.move.x += (0.0f - g_Player.move.x)*0.1f;	//�ړI�̒l-���݂̒l*�����W��
	
	 
	g_Player.bIsJamping  = !CollisionBlock(&g_Player.pos,&g_Player.posOld,
									&g_Player.move, PLAYER_SIZE_X , PLAYER_SIZE_Y );

	 CollisionEnemy(&g_Player.pos,
		&g_Player.move, PLAYER_SIZE_X, PLAYER_SIZE_Y);

	//��ʏ㉺�ȏ�ɂ����Ȃ�
	if (g_Player.pos.y >= 710)
	{
		g_Player.pos.y = 710;
		g_Player.move.y = 0;
	}
	if (g_Player.pos.y <= 10)
	{
		g_Player.pos.y = 10;
		g_Player.move.y = 0;
	}

	//���_���W�̍X�V
	pVtx[0].pos = D3DXVECTOR3(g_Player.pos.x - PLAYER_SIZE_X/2 , g_Player.pos.y - PLAYER_SIZE_Y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(g_Player.pos.x + PLAYER_SIZE_X/2 , g_Player.pos.y - PLAYER_SIZE_Y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(g_Player.pos.x - PLAYER_SIZE_X/2 , g_Player.pos.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(g_Player.pos.x + PLAYER_SIZE_X/2 , g_Player.pos.y, 0.0f);
	
	//���_�o�b�t�@���A�����b�N����                     
		g_pVtxBuffPlayer->Unlock();
}

//�v���C���[�̕`�揈��
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffPlayer, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTexturePlayer);
	 
	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}
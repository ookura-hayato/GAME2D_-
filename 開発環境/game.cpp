//==================================
//�����b �A�N�V����(game.cpp)
//	Author:�@��q����
//==================================
#include "game.h"
#include "main.h"

//�Q�[����ʂ̏���������
void InitGame(void)
{
	//�w�i�̏���������
	InitBg();

	//�v���C���[�̏���������
	InitPlayer();

	//�u���b�N�̏���������
	InitBlock();

	//�G�̏���������
	InitEnemy();

	//�X�R�A�̏�����
	InitScore();

	//�^�C�}�[�̏���������
	InitTimer();

	//�T�E���h�̍Đ�
	PlaySound(SOUND_LABEL_BGM001);
}

//�Q�[����ʂ̏I������
void UninitGame(void)
{
	//�T�E���h�̒�~
	StopSound();

	//�w�i�̏���������
	InitBg();

	//�v���C���[�̏I������
	UninitPlayer();

	//�u���b�N�̏I������
	UninitBlock();

	//�G�̏I������
	UninitEnemy();

	//�X�R�A�̏I������
	UninitScore();

	//�^�C�}�[�̏I������
	UninitTimer();

}

//�Q�[����ʂ̍X�V����
void UpdateGame(void)
{
	//�w�i�̍X�V����
	UpdateBg();

	//�v���C���[�̍X�V����
	UpdatePlayer();

	//�u���b�N�̍X�V����
	UpdateBlock();

	//�G�̍X�V����
	UpdateEnemy();

	//�X�R�A�̍X�V����
	UpdateScore();

	//�^�C�}�[�̍X�V����
	UpdateTimer();

	//if (GetKeyboardTrigger(DIK_RETURN) == true)
	//{
	//	//���U���g��ʂɑJ��
	//	SetMode(MODE_RESULT);
	//}
}
//�Q�[����ʂ̕`�揈��
void DrawGame(void)
{
	//�w�i�̕`�揈��
	DrawBg();

	//�v���C���[�̕`�揈��
	DrawPlayer();

	//�u���b�N�̕`�揈��
	DrawBlock();
	
	//�G�̕`�揈��
	DrawEnemy();

	//�X�R�A�̕`�揈��
	DrawScore();

	//�^�C�}�[�̕`�揈��
	DrawTimer();
}
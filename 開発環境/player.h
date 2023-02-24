//==================================
//�����b �A�N�V����(player.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _PLAYER_H_			//���̃}�N����`������Ȃ�������
#define _PLAYER_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//�C���N���[�h�t�@�C��
#include "main.h"

//�v���C���[�̍\����
typedef struct
{
	D3DXVECTOR3 pos;		//���݂̈ʒu
	D3DXVECTOR3 posOld;		//�O��̈ʒu
	D3DXVECTOR3 move;		//�ړ���
	float fWidth;			//��
	float fHeight;			//����
	int nCounterAnim;		//�J�E���^�[
	int nPatternAnim;		//�p�^�[���ԍ�
	int nDirectionMove;		//����
	bool bIsJamping;		//�W�����v��
}PLAYER;

//�}�N����`
#define PLAYER_SIZE_X (100)
#define PLAYER_SIZE_Y (100)

//�v���g�^�C�v�錾
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

#endif




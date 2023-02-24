//==================================
//�����b �A�N�V����(block.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _BLOCK_H_			//���̃}�N����`������Ȃ�������
#define _BLOCK_H_			//2�d�C���N���[�h�h�~�̃}�N����`
#include"main.h"

// �e�̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;		//�ʒu
	float fWidth;			//��
	float fHeight;			//����
	bool bUse;				//�g�p���Ă��邩�ǂ���
}BLOCK;

//�v���g�^�C�v�錾
void InitBlock(void);
void UninitBlock(void);
void UpdateBlock(void);
void DrawBlock(void);
void SetBlock(D3DXVECTOR3 pos, float fWidth, float fHeight);
bool CollisionBlock(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pPosOld,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight);
#endif

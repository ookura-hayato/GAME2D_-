//==================================
//�����b �A�N�V����(score.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _SCORE_H_			//���̃}�N����`������Ȃ�������
#define _SCORE_H_			//2�d�C���N���[�h�h�~�̃}�N����`
#include "main.h"
//�v���g�^�C�v�錾
void InitScore(void);
void UninitScore(void);
void UpdateScore(void);
void DrawScore(void);
void SetScore(int nScore,D3DXVECTOR3 pos);
void AddScore(int nValue);
int GetScore(void);
#endif

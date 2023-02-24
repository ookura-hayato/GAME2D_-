//==================================
//�����b �A�N�V����(enemy.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _ENEMY_H_			//���̃}�N����`������Ȃ�������
#define _ENEMY_H_			//2�d�C���N���[�h�h�~�̃}�N����`
#include"main.h"

//�}�N����`
#define MAX_ENEMY		(900)				//�G�̍ő吔
#define NUM_ENEMY		(3)					//�G�̎��
#define ENEMY_SIZE_X (50)
#define ENEMY_SIZE_Y (50)

//�G�̏��
typedef enum
{
	ENEMYSTATE_NORMAL = 0,//�ʏ�
	ENEMYSTATE_DAMAGE,//�_���[�W���
	ENEMYSTATE_MAX
}ENEMYSTATE;

// �G�̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;		//���݂̈ʒu
	D3DXVECTOR3 posOld;		//�O��̈ʒu
	D3DXVECTOR3 move;		//�ړ���
	float fWidth;			//��
	float fHeight;			//����
	int nType;				//���
	//int nLife;				//�̗�
	bool bUse;				//�g�p���Ă��邩�ǂ���
	ENEMYSTATE state;		//���
	int nCounterState;		//��ԃJ�E���^�[
}Enemy;


//�v���g�^�C�v�錾
void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);
void SetEnemy(D3DXVECTOR3 pos, int nType);
Enemy * GetEnemy(void);
void CollisionEnemy(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight);
#endif
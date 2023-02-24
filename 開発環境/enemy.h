//==================================
//制作基礎 アクション(enemy.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _ENEMY_H_			//このマクロ定義がされなかったら
#define _ENEMY_H_			//2重インクルード防止のマクロ定義
#include"main.h"

//マクロ定義
#define MAX_ENEMY		(900)				//敵の最大数
#define NUM_ENEMY		(3)					//敵の種類
#define ENEMY_SIZE_X (50)
#define ENEMY_SIZE_Y (50)

//敵の状態
typedef enum
{
	ENEMYSTATE_NORMAL = 0,//通常
	ENEMYSTATE_DAMAGE,//ダメージ状態
	ENEMYSTATE_MAX
}ENEMYSTATE;

// 敵の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;		//現在の位置
	D3DXVECTOR3 posOld;		//前回の位置
	D3DXVECTOR3 move;		//移動量
	float fWidth;			//幅
	float fHeight;			//高さ
	int nType;				//種類
	//int nLife;				//体力
	bool bUse;				//使用しているかどうか
	ENEMYSTATE state;		//状態
	int nCounterState;		//状態カウンター
}Enemy;


//プロトタイプ宣言
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
//==================================
//制作基礎 アクション(player.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _PLAYER_H_			//このマクロ定義がされなかったら
#define _PLAYER_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

//プレイヤーの構造体
typedef struct
{
	D3DXVECTOR3 pos;		//現在の位置
	D3DXVECTOR3 posOld;		//前回の位置
	D3DXVECTOR3 move;		//移動量
	float fWidth;			//幅
	float fHeight;			//高さ
	int nCounterAnim;		//カウンター
	int nPatternAnim;		//パターン番号
	int nDirectionMove;		//向き
	bool bIsJamping;		//ジャンプ中
}PLAYER;

//マクロ定義
#define PLAYER_SIZE_X (100)
#define PLAYER_SIZE_Y (100)

//プロトタイプ宣言
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

#endif




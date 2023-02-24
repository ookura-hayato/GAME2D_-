//==================================
//制作基礎 アクション(block.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _BLOCK_H_			//このマクロ定義がされなかったら
#define _BLOCK_H_			//2重インクルード防止のマクロ定義
#include"main.h"

// 弾の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;		//位置
	float fWidth;			//幅
	float fHeight;			//高さ
	bool bUse;				//使用しているかどうか
}BLOCK;

//プロトタイプ宣言
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

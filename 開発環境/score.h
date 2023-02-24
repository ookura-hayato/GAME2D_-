//==================================
//制作基礎 アクション(score.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _SCORE_H_			//このマクロ定義がされなかったら
#define _SCORE_H_			//2重インクルード防止のマクロ定義
#include "main.h"
//プロトタイプ宣言
void InitScore(void);
void UninitScore(void);
void UpdateScore(void);
void DrawScore(void);
void SetScore(int nScore,D3DXVECTOR3 pos);
void AddScore(int nValue);
int GetScore(void);
#endif

//==================================
//制作基礎 アクション(title.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _TITLE_H_			//このマクロ定義がされなかったら
#define _TITLE_H_			//2重インクルード防止のマクロ定義
#include "main.h"
//プロトタイプ宣言
void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);
#endif
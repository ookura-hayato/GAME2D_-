//==================================
//制作基礎 アクション(tutorial.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _TUTORIAL_H_			//このマクロ定義がされなかったら
#define _TUTORIAL_H_			//2重インクルード防止のマクロ定義
#include "main.h"
//プロトタイプ宣言
void InitTutorial(void);
void UninitTutorial(void);
void UpdateTutorial(void);
void DrawTutorial(void);
#endif
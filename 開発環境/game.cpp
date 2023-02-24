//==================================
//制作基礎 アクション(game.cpp)
//	Author:　大倉隼翔
//==================================
#include "game.h"
#include "main.h"

//ゲーム画面の初期化処理
void InitGame(void)
{
	//背景の初期化処理
	InitBg();

	//プレイヤーの初期化処理
	InitPlayer();

	//ブロックの初期化処理
	InitBlock();

	//敵の初期化処理
	InitEnemy();

	//スコアの初期化
	InitScore();

	//タイマーの初期化処理
	InitTimer();

	//サウンドの再生
	PlaySound(SOUND_LABEL_BGM001);
}

//ゲーム画面の終了処理
void UninitGame(void)
{
	//サウンドの停止
	StopSound();

	//背景の初期化処理
	InitBg();

	//プレイヤーの終了処理
	UninitPlayer();

	//ブロックの終了処理
	UninitBlock();

	//敵の終了処理
	UninitEnemy();

	//スコアの終了処理
	UninitScore();

	//タイマーの終了処理
	UninitTimer();

}

//ゲーム画面の更新処理
void UpdateGame(void)
{
	//背景の更新処理
	UpdateBg();

	//プレイヤーの更新処理
	UpdatePlayer();

	//ブロックの更新処理
	UpdateBlock();

	//敵の更新処理
	UpdateEnemy();

	//スコアの更新処理
	UpdateScore();

	//タイマーの更新処理
	UpdateTimer();

	//if (GetKeyboardTrigger(DIK_RETURN) == true)
	//{
	//	//リザルト画面に遷移
	//	SetMode(MODE_RESULT);
	//}
}
//ゲーム画面の描画処理
void DrawGame(void)
{
	//背景の描画処理
	DrawBg();

	//プレイヤーの描画処理
	DrawPlayer();

	//ブロックの描画処理
	DrawBlock();
	
	//敵の描画処理
	DrawEnemy();

	//スコアの描画処理
	DrawScore();

	//タイマーの描画処理
	DrawTimer();
}
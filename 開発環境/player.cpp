//==================================
//制作基礎 アクション(player.cpp)
//	Author:　大倉隼翔
//==================================
#include "player.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTexturePlayer = NULL;			//テクスチャへのポインタ								//頂点情報の格納
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffPlayer = NULL;	//頂点バッファへのポインタ
PLAYER g_Player;

//プレイヤー初期化処理
void InitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ

	//デバイスの取得
	pDevice = GetDevice();
	
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,"data/TEXTURE/レイヤー 0.1.png",&g_pTexturePlayer);
	
	g_Player.pos = D3DXVECTOR3(450.0f, 550.0f, 0.0f);			//位置を初期化
	g_Player.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//移動量を初期化

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D,
		D3DPOOL_MANAGED, &g_pVtxBuffPlayer,NULL);
	VERTEX_2D*pVtx;										//頂点情報へのポインタ
	g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);		//頂点バッファをロックし、頂点情報へのポインタを取得

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	
	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.5f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.5f, 1.0f);

	//頂点バッファをアンロックする
	g_pVtxBuffPlayer->Unlock();
}

//プレイヤーの終了処理
void UninitPlayer(void)
{
	//テクスチャの破棄
	if (g_pTexturePlayer != NULL)
	{
		g_pTexturePlayer->Release();
		g_pTexturePlayer = NULL;
	}
	
	//頂点バッファの破棄
	if (g_pVtxBuffPlayer != NULL)
	{
		g_pVtxBuffPlayer->Release();
		g_pVtxBuffPlayer = NULL;
	}
}

//プレイヤーの更新処理
void UpdatePlayer(void)
{
	VERTEX_2D *pVtx;			//頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffPlayer->Lock(0, 0, (void**)&pVtx, 0);
	if (GetKeyboardPress(DIK_A) == true)
	{//Aキーが押された
		//左移動
		
			g_Player.move.x = -5.0f;
			if (g_Player.move.x)
			{
				/*g_Player.nCounterAnim++;
				if (g_Player.nCounterAnim == 4)
				{
					g_Player.nPatternAnim = (g_Player.nPatternAnim + 1) % 20;*/
					pVtx[0].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 0.0f);
					pVtx[1].tex = D3DXVECTOR2((1.0f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 0.0f);
					pVtx[2].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 1.0f);
					pVtx[3].tex = D3DXVECTOR2((1.0f /*+ g_Player.nPatternAnim*0.25f*/) * 1, 1.0f);
				//	if (g_Player.nPatternAnim == 0)//総パターンを超えた
				//	{
				//		g_Player.nPatternAnim = false;
				//	}
				//	g_Player.nCounterAnim = 0;
				//}
			}
	}

	if (GetKeyboardPress(DIK_D) == true)
	{//Dキーが押された
	 //右移動
		
			g_Player.move.x = 5.0f;
			if (g_Player.move.x)
			{
				/*g_Player.nCounterAnim++;
				if (g_Player.nCounterAnim == 4)
				{
					g_Player.nPatternAnim = (g_Player.nPatternAnim + 1) % 20;*/
					pVtx[0].tex = D3DXVECTOR2((0.0f/* + g_Player.nPatternAnim*0.25f*/)*1 , 0.0f);
					pVtx[1].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/)*1, 0.0f);
					pVtx[2].tex = D3DXVECTOR2((0.0f /*+ g_Player.nPatternAnim*0.25f*/) *1, 1.0f);
					pVtx[3].tex = D3DXVECTOR2((0.5f /*+ g_Player.nPatternAnim*0.25f*/) *1, 1.0f);
				//	if (g_Player.nPatternAnim == 0)//総パターンを超えた
				//	{
				//		g_Player.nPatternAnim = false;
				//	}
				//	g_Player.nCounterAnim = 0;
				//}
			}
	}

	if (GetKeyboardTrigger(DIK_SPACE) == true)
	{//SPACEキーが押された
		//ジャンプ
		if(g_Player.bIsJamping ==false)
		{ 
			g_Player.bIsJamping = true;
			g_Player.move.y -= 30.0f;
		}
	}

	g_Player.move.y += 1.0f;		//重力加増
	//前回の位置を保存
	g_Player.posOld = g_Player.pos;
	//画面移動(左右)
	if (g_Player.pos.x + 50.0f < 0.0f)
	{
		g_Player.pos.x = SCREEN_WIDTH + 50.0f;
		g_Player.posOld.x = SCREEN_WIDTH + 50.0f;
	}

	else if (g_Player.pos.x - 50.0f > SCREEN_WIDTH)
	{
		g_Player.pos.x = -50.0f;
		g_Player.posOld.x = -50.0f;
	}

	//位置を更新
	g_Player.pos.x += g_Player.move.x;
	g_Player.pos.y += g_Player.move.y;

	//移動量更新（減衰）
	g_Player.move.x += (0.0f - g_Player.move.x)*0.1f;	//目的の値-現在の値*減衰係数
	
	 
	g_Player.bIsJamping  = !CollisionBlock(&g_Player.pos,&g_Player.posOld,
									&g_Player.move, PLAYER_SIZE_X , PLAYER_SIZE_Y );

	 CollisionEnemy(&g_Player.pos,
		&g_Player.move, PLAYER_SIZE_X, PLAYER_SIZE_Y);

	//画面上下以上にいかない
	if (g_Player.pos.y >= 710)
	{
		g_Player.pos.y = 710;
		g_Player.move.y = 0;
	}
	if (g_Player.pos.y <= 10)
	{
		g_Player.pos.y = 10;
		g_Player.move.y = 0;
	}

	//頂点座標の更新
	pVtx[0].pos = D3DXVECTOR3(g_Player.pos.x - PLAYER_SIZE_X/2 , g_Player.pos.y - PLAYER_SIZE_Y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(g_Player.pos.x + PLAYER_SIZE_X/2 , g_Player.pos.y - PLAYER_SIZE_Y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(g_Player.pos.x - PLAYER_SIZE_X/2 , g_Player.pos.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(g_Player.pos.x + PLAYER_SIZE_X/2 , g_Player.pos.y, 0.0f);
	
	//頂点バッファをアンロックする                     
		g_pVtxBuffPlayer->Unlock();
}

//プレイヤーの描画処理
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffPlayer, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTexturePlayer);
	 
	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}
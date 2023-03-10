//==================================
//制作基礎 アクション(result.cpp)
//	Author:　大倉隼翔
//==================================
#include "result.h"

LPDIRECT3DTEXTURE9 g_pTextureResult = {};	//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffResult = NULL;	//頂点バッファへのポインタ
int g_nRisultScore;

//リザルト画面の初期化処理
void InitResult(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	pDevice = GetDevice();		//デバイスの取得

	g_nRisultScore = GetScore();

	D3DXCreateTextureFromFile(pDevice,"data//TEXTURE//bg003.jpg",&g_pTextureResult);

	//頂点バッファの設定
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,	//確保するバッファのサイズ 
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,	//頂点フォーマット
		D3DPOOL_MANAGED,
		&g_pVtxBuffResult,
		NULL);

	VERTEX_2D *pVtx;	//頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffResult->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

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
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロックする
	g_pVtxBuffResult->Unlock();

	//サウンドの再生
	PlaySound(SOUND_LABEL_BGM002);

	InitScore();
	SetScore(g_nRisultScore, D3DXVECTOR3(500.0f,300.0f,0.0f));
}

//リザルト画面の終了処理
void UninitResult(void)
{
	//サウンドの停止
	StopSound();

	//バッファ破棄
	if (g_pVtxBuffResult != NULL)
	{
		g_pVtxBuffResult->Release();
		g_pVtxBuffResult = NULL;
	}

	//テクスチャ破棄
	if (g_pTextureResult != NULL)
	{
		g_pTextureResult->Release();
		g_pTextureResult = NULL;
	}

	UninitScore();
}

//リザルト画面の更新処理
void UpdateResult(void)
{
	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		//タイトル画面に遷移
		SetMode(MODE_TITLE);
	}
}

//リザルト画面の描画処理
void DrawResult(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	pDevice = GetDevice();	//デバイスの取得

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffResult, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャ設定
	pDevice->SetTexture(0, g_pTextureResult);

	//ポリゴン描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);	//プリミティブの種類

	DrawScore();
}
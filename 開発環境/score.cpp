//==================================
//制作基礎 アクション(score.cpp)
//	Author:　大倉隼翔
//==================================
#include"score.h"
//マクロ定義
#define NUM_SCORE (8)

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureScore = NULL;			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffScore = NULL;		//頂点バッファへのポインタ
D3DXVECTOR3 g_posScore;								//スコアの位置
int g_nScore;										//スコアの値

//スコアの初期化処理
void InitScore(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	pDevice = GetDevice();//デバイスの取得

  //テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,"data/TEXTURE/number000.png",&g_pTextureScore);

	g_posScore = D3DXVECTOR3(850.0f, 10.0f, 0.0f);	//位置の初期化
	g_nScore = 0;	//値の初期化

	//頂点バッファの設定
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4* NUM_SCORE,	//確保するバッファのサイズ 
		D3DUSAGE_WRITEONLY,FVF_VERTEX_2D,D3DPOOL_MANAGED,&g_pVtxBuffScore,NULL);

	VERTEX_2D *pVtx;	//頂点情報のポインタ
	
	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffScore->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(g_posScore.x + (50.0f * nCntScore), g_posScore.y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_posScore.x + 50 + (50.0f * nCntScore), g_posScore.y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(g_posScore.x + (50.0f * nCntScore), g_posScore.y + 50.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_posScore.x  + 50+ (50.0f * nCntScore), g_posScore.y + 50.0f, 0.0f);

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
		pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

		pVtx += 4;

	}
	//頂点バッファをアンロックする
	g_pVtxBuffScore->Unlock();
}

//スコアの終了処理
void UninitScore(void)
{
	//バッファ破棄
	if (g_pVtxBuffScore != NULL)
	{
		g_pVtxBuffScore->Release();
		g_pVtxBuffScore = NULL;
	}

	//テクスチャ破棄
	if (g_pTextureScore != NULL)
	{
		g_pTextureScore->Release();
		g_pTextureScore = NULL;
	}
}

//スコアの更新処理
void UpdateScore(void)
{

}

//スコアの描画処理
void DrawScore(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	pDevice = GetDevice();	//デバイスの取得

							//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffScore, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureScore);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,4 * nCntScore,2);
	}
}

//スコアの設定処理
void SetScore(int nScore, D3DXVECTOR3 pos)
{
	VERTEX_2D *pVtx;
	float aPosTexU[NUM_SCORE];											//各桁の数値を格納
	int nCntScore;
	g_nScore = nScore;

	aPosTexU[0] = ((g_nScore % 100000000) / 10000000) * 0.1f;
	aPosTexU[1] = ((g_nScore % 10000000) / 1000000) * 0.1f;
	aPosTexU[2] = ((g_nScore % 1000000) / 100000) * 0.1f;
	aPosTexU[3] = ((g_nScore % 100000) / 10000) * 0.1f;
	aPosTexU[4] = ((g_nScore % 10000) / 1000) * 0.1f;
	aPosTexU[5] = ((g_nScore % 1000) / 100) * 0.1f;
	aPosTexU[6] = ((g_nScore % 100) / 10) * 0.1f;
	aPosTexU[7] =  (g_nScore % 10) * 0.1f;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffScore->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{
		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 1.0f);

		pVtx += 4;
	}
	//頂点座標をアンロック
	g_pVtxBuffScore->Unlock();
}

//スコアの加算処理
void AddScore(int nValue)
{
	VERTEX_2D *pVtx;
	float aPosTexU[NUM_SCORE];											//各桁の数値を格納
	g_nScore += nValue;

	aPosTexU[0] = ((g_nScore % 100000000) / 10000000) * 0.1f;
	aPosTexU[1] = ((g_nScore % 10000000) / 1000000) * 0.1f;
	aPosTexU[2] = ((g_nScore % 1000000) / 100000) * 0.1f;
	aPosTexU[3] = ((g_nScore % 100000) / 10000) * 0.1f;
	aPosTexU[4] = ((g_nScore % 10000) / 1000) * 0.1f;
	aPosTexU[5] = ((g_nScore % 1000) / 100) * 0.1f;
	aPosTexU[6] = ((g_nScore % 100) / 10) * 0.1f;
	aPosTexU[7] =  (g_nScore % 10) * 0.1f;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffScore->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntScore = 0; nCntScore < NUM_SCORE; nCntScore++)
	{
		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f + aPosTexU[nCntScore], 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f + aPosTexU[nCntScore], 1.0f);

		pVtx += 4;
	}
	//頂点座標をアンロック
	g_pVtxBuffScore->Unlock();
}

int GetScore(void)
{
	return g_nScore;
}
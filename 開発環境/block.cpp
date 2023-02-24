//==================================
//制作基礎 アクション(block.cpp)
//	Author:　大倉隼翔
//==================================
#include"block.h"
//マクロ定義
#define MAX_BLOCK		(128)					//ブロックの最大数

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureBlock[MAX_BLOCK] = {};			//テクスチャへのポインタ								//頂点情報の格納
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffBlock = NULL;	//頂点バッファへのポインタ
BLOCK g_aBlock[MAX_BLOCK];						//ブロックの情報

//ブロックの初期化処理
void InitBlock(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/block001.jpg", &g_pTextureBlock[0]);

	//ブロックの情報の初期化
	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		g_aBlock[nCntBlock].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBlock[nCntBlock].bUse = false;
		g_aBlock[nCntBlock].fWidth = 1000.0f;
		g_aBlock[nCntBlock].fHeight = 40.0f;
	}
	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 44 * MAX_BLOCK,
		D3DUSAGE_WRITEONLY, FVF_VERTEX_2D,
		D3DPOOL_MANAGED, &g_pVtxBuffBlock, NULL);

	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffBlock->Lock(0, 0, (void**)&pVtx, 0);
		
	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		
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
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(40.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(40.0f, 1.0f);
		pVtx += 4;			//頂点データのポインタを4つ分進める
	}
	//頂点バッファをアンロックする
	g_pVtxBuffBlock->Unlock();

	SetBlock(D3DXVECTOR3(-150.0f, 400.0f, 0.0f), 5, 1);		//左
	SetBlock(D3DXVECTOR3(1400.0f, 400.0f, 0.0f), 1, 1);		//右
	SetBlock(D3DXVECTOR3(800.0f, 700.0f, 0.0f), 4, 40);		//下1
	SetBlock(D3DXVECTOR3(20.0f, 700.0f, 0.0f), 4, 40);		//下2
	SetBlock(D3DXVECTOR3(800.0f, 0.0f, 0.0f), 4, 40);		//上1
	SetBlock(D3DXVECTOR3(20.0f, 0.0f, 0.0f), 4, 40);		//上2
}

//ブロックの終了処理
void UninitBlock(void)
{
	//テクスチャの破棄
	
		if (g_pTextureBlock[0] != NULL)
		{
			g_pTextureBlock[0]->Release();
			g_pTextureBlock[0] = NULL;
		}
	
	//頂点バッファの破棄
	
		if (g_pVtxBuffBlock != NULL)
		{
			g_pVtxBuffBlock->Release();
			g_pVtxBuffBlock = NULL;
		}
}

//ブロックの更新処理
void UpdateBlock(void)
{

}

//ブロックの描画処理
void DrawBlock(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスへのポインタ
	
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffBlock, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		if (g_aBlock[nCntBlock].bUse == true)
		{//ブロックが使用されているとき
			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureBlock[0]);
			//ポリゴン描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類
				nCntBlock * 4,//描画する画像の最初の頂点インデックス
				2);	//ポリゴン数
		}                                                        
	}
}

//ブロックの設定処理
void SetBlock(D3DXVECTOR3 pos, float fWidth, float fHeight)
{
	VERTEX_2D * pVtx;

	//頂点情報をロックし、頂点情報へのポインタを取得
	g_pVtxBuffBlock->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{
		if (g_aBlock[nCntBlock].bUse == false)
		{
			g_aBlock[nCntBlock].pos = pos;

			//頂点座標更新
			pVtx[0].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2, g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2, 0.0f);
			g_aBlock[nCntBlock].bUse = true;
			break;
		}
		//頂点データのポインタを4つ分進める
		pVtx += 4;
	}
	//頂点バッファをアンロックする
	g_pVtxBuffBlock->Unlock();
}


//当たり判定（ブロック）
bool CollisionBlock(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pPosOld,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight)
{
	bool bIsLanding = false;
	for(int nCntBlock = 0; nCntBlock < MAX_BLOCK; nCntBlock++)
	{ 
		if (g_aBlock[nCntBlock].bUse == true)
		{
			if (//判定（上）
				(g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) >= pPosOld->y
				&& (g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) < pPos->y
				&& (g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) > (pPos->x - fWidith/2)
				&&(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) < (pPos->x + fWidith/2))
			{
				bIsLanding = true;	//着地している
				pPos->y = g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2;
				pMove->y = 0.0f;
			}
			 if (//判定(下)
				(g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) <= pPosOld->y - PLAYER_SIZE_Y
				&& (g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) > pPos->y - PLAYER_SIZE_Y
				&& (g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) > (pPos->x - fWidith/2)
				&& (g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) < (pPos->x + fWidith/2))
			{
				
				pPos->y = g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2 + PLAYER_SIZE_Y;
				pMove->y = 0.0f;
			}
			if(//判定(左)
				(g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) >= pPosOld->x + PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2) < pPos->x + PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) > (pPos->y - fHeight/2) 
				&& (g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) < pPos->y )
			{
				
				pPos->x = g_aBlock[nCntBlock].pos.x - g_aBlock[nCntBlock].fWidth/2 - PLAYER_SIZE_X/2;
				pMove->x= 0.0f;
			}
		 if (//判定(右)
				(g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) <= pPosOld->x - PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2) > pPos->x - PLAYER_SIZE_X/2
				&& (g_aBlock[nCntBlock].pos.y + g_aBlock[nCntBlock].fHeight/2) > (pPos->y - fHeight/2) 
				&& (g_aBlock[nCntBlock].pos.y - g_aBlock[nCntBlock].fHeight/2) < pPos->y )
			{

				pPos->x = g_aBlock[nCntBlock].pos.x + g_aBlock[nCntBlock].fWidth/2 + PLAYER_SIZE_X/2;
				pMove->x = 0.0f;
			}
		}
	}
	return bIsLanding;
}
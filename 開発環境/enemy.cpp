//==================================
//制作基礎 アクション(enemy.cpp)
//	Author:　大倉隼翔
//==================================
#include"enemy.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureEnemy[NUM_ENEMY] = {};			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffEnemy = NULL;				//頂点バッファへのポインタ
Enemy g_aEnemy[MAX_ENEMY];									//敵の情報

//敵の初期化処理
void InitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntEnemy;

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/purin.png", &g_pTextureEnemy[0]);
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/jelly.png", &g_pTextureEnemy[1]);
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/プリンアラモード.png", &g_pTextureEnemy[2]);
	
	//敵の情報の初期化
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		g_aEnemy[nCntEnemy].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aEnemy[nCntEnemy].nType = 0;
		//g_aEnemy[nCntEnemy].nLife = 10;
		g_aEnemy[nCntEnemy].fWidth = 50;
		g_aEnemy[nCntEnemy].fHeight = 50;
		g_aEnemy[nCntEnemy].bUse = false;
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ENEMY,
		D3DUSAGE_WRITEONLY, FVF_VERTEX_2D,
		D3DPOOL_MANAGED, &g_pVtxBuffEnemy, NULL);
	VERTEX_2D*pVtx;	//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);
	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
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
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;			//頂点データのポインタを4つ分進める
	}

	//頂点バッファをアンロックする
	g_pVtxBuffEnemy->Unlock();

	SetEnemy(D3DXVECTOR3(555.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(55.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(1100.0f, 680.0f, 0.0f), 1);
	SetEnemy(D3DXVECTOR3(900.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(1270.0f, 380.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(200.0f, 380.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(10.0f, 380.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(1111.0f, 380.0f, 0.0f), 1);
	SetEnemy(D3DXVECTOR3(300.0f, 680.0f, 0.0f), 1);
	SetEnemy(D3DXVECTOR3(700.0f, 680.0f, 0.0f), 0);
	SetEnemy(D3DXVECTOR3(550.0f, 100.0f, 0.0f), 0);
}

//敵の終了処理
void UninitEnemy(void)
{
	//サウンドの停止
	StopSound();

	//テクスチャの破棄
	for (int nCntEnemy = 0; nCntEnemy<NUM_ENEMY; nCntEnemy++)
	{ 
		if (g_pTextureEnemy[nCntEnemy] != NULL)
		{
			g_pTextureEnemy[nCntEnemy]->Release();
			g_pTextureEnemy[nCntEnemy] = NULL;
		}

	}

	//頂点バッファの破棄
		if (g_pVtxBuffEnemy != NULL)
		{
			g_pVtxBuffEnemy->Release();
			g_pVtxBuffEnemy = NULL;
		}
}

//敵の更新処理
void UpdateEnemy(void)
{
	int nCntEnemy;
	VERTEX_2D * pVtx;
	//頂点情報をロックし、頂点情報へのポインタを取得
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{//弾が使用されている
			switch(g_aEnemy[nCntEnemy].state)
			{
			case ENEMYSTATE_NORMAL:

				break;
			case ENEMYSTATE_DAMAGE:
				g_aEnemy[nCntEnemy].nCounterState--;
				if (g_aEnemy[nCntEnemy].nCounterState<=0)
				{
					g_aEnemy[nCntEnemy].state = ENEMYSTATE_NORMAL;
					//頂点カラーの設定
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				break;
				
			}

			//頂点座標更新
			pVtx[0].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE_Y, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y - ENEMY_SIZE_Y, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x - ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y , 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aEnemy[nCntEnemy].pos.x + ENEMY_SIZE_X/2, g_aEnemy[nCntEnemy].pos.y , 0.0f);

		}
		pVtx += 4;			//頂点データのポインタを4つ分進める
	}

	//頂点バッファをアンロックする
	g_pVtxBuffEnemy->Unlock();
}

//敵の描画処理
void DrawEnemy(void)
{
	
	LPDIRECT3DDEVICE9 pDevice;		//デバイスへのポインタ
	int nCntEnemy;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffEnemy, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == true)
		{	//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureEnemy[g_aEnemy[nCntEnemy].nType]);
			//敵の描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	nCntEnemy * 4,2);	
		}
	}
}
//敵の設定処理
void SetEnemy(D3DXVECTOR3 pos, int nType)
{
	int nCntEnemy;

	VERTEX_2D * pVtx;

	//頂点情報をロックし、頂点情報へのポインタを取得
	g_pVtxBuffEnemy->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_aEnemy[nCntEnemy].bUse == false)
		{//敵が使用されていない場合

			g_aEnemy[nCntEnemy].pos = pos;
			g_aEnemy[nCntEnemy].nType = nType;
		/*	g_aEnemy[nCntEnemy].nLife = 10;*/
			g_aEnemy[nCntEnemy].bUse = true;

			break;
		}

		pVtx += 4;			//頂点データのポインタを4つ分進める
	}

	//頂点バッファをアンロックする
	g_pVtxBuffEnemy->Unlock();
}

//敵の取得
Enemy * GetEnemy(void)
{
	Enemy *pEnemy = g_aEnemy;

	//返り値
	return pEnemy;
}

//当たり判定（敵）
void CollisionEnemy(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight)
{
	Enemy*pEnemy;
	pEnemy = GetEnemy();
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (pEnemy->bUse == true)
		{
			if (//判定
				(g_aEnemy[nCntEnemy].pos.y - g_aEnemy[nCntEnemy].fHeight/2) <= pPos->y
				&& (g_aEnemy[nCntEnemy].pos.y + g_aEnemy[nCntEnemy].fHeight/2) >= pPos->y - PLAYER_SIZE_Y/2
				&& (g_aEnemy[nCntEnemy].pos.x - g_aEnemy[nCntEnemy].fWidth/2) <= pPos->x + PLAYER_SIZE_X / 2
				&& (g_aEnemy[nCntEnemy].pos.x + g_aEnemy[nCntEnemy].fWidth/2) >= pPos->x - PLAYER_SIZE_X / 2)
			{
				if (g_aEnemy[nCntEnemy].bUse == true)
				{
					if (g_aEnemy[nCntEnemy].nType == 0)
					{
						AddScore(+300);
						g_aEnemy[nCntEnemy].bUse = false;
					}
					else if (g_aEnemy[nCntEnemy].nType == 1)
					{
						AddScore(-500);
						g_aEnemy[nCntEnemy].bUse = false;
					}
					else if (g_aEnemy[nCntEnemy].nType == 2)
					{
						AddScore(+3000);
						g_aEnemy[nCntEnemy].bUse = false;
						//サウンドの再生
						PlaySound(SOUND_LABEL_SE_GET);
					}
					//サウンドの再生
					PlaySound(SOUND_LABEL_SE_GET2);
				}
			}
		}
		pEnemy++;
	}
}
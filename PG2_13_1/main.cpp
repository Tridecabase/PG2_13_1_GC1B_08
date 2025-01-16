#include <Novice.h>
#include "player.h"
#include "enemy.h"
#include "collision_manager.h"

const char kWindowTitle[] = "GC1B_08_ジョ_シセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//プレイヤーの初期化
	Player* player = new Player(640, 600, 10, 10, 30);

	//敵の初期化
	Actor* enemy[3]{};
	for (int i = 0; i < 3; i++) 
	{
		enemy[i] = new Enemy(700 - 60 * i, 400 - 50 * i, 10 - i, 0, 20);
	}

	Actor::isActive = true;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		for (int i = 0; i < 3; i++) 
		{
			//敵の更新処理
			enemy[i]->Update();
			
			//弾と敵を当たると、すべての敵が消える
			for (int j = 0; j < MAX_BULLET; j++)
			{
				if (player->bullet[j]) 
				{
					if (player->bullet[j]->isAlive && enemy[i]->isAlive) 
					{
						COLLISION_MANAGER::CircleCircle(player->bullet[j], enemy[i]);
					}
				}
			}
			if (!Actor::isActive) 
			{
				enemy[i]->isAlive = false;
			}
			else 
			{
				enemy[i]->isAlive = true;
			}

			//Rを押して、消えた敵を再生する
			if (keys[DIK_R] && !preKeys[DIK_R]) 
			{
				Actor::isActive = true;
			}
		}

		//プレイヤーの更新処理
		player->Update(); 

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//背景の描画
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x696969ff, kFillModeSolid);

		//敵の描画
		for (int i = 0; i < 3; i++) 
		{
			enemy[i]->Draw();
		}
		//プレイヤーの描画
		player->Draw();

		//説明
		for (int i = 0; i < 3; i++)
		{
			Novice::ScreenPrintf(0, i * 20, "Enemy%dIsAlive : %d", i, enemy[i]->isAlive);
		}
		Novice::ScreenPrintf(0,60, "playerMove : WASD");
		Novice::ScreenPrintf(0, 80, "shot : space");
		Novice::ScreenPrintf(0, 100, "enemyReset : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			delete player;
			for (int i = 0; i < 3; i++) {
				delete enemy[i];
			}
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
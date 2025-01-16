#ifndef ENEMY_H
#define ENEMY_H

#include "actor.h"

class Enemy : public Actor
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">x座標</param>
	/// <param name="posY">y座標</param>
	/// <param name="speedX">速度x</param>
	/// <param name="speedY">速度y</param>
	/// <param name="radius">半径</param>
	Enemy(int posX, int posY, int speedX, int speedY, int radius);

	//更新処理
	void Update() override;
	//描画処理
	void Draw() override;
};

#endif // !ENEMY_H
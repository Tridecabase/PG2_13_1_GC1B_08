#ifndef BULLET_H
#define BULLET_H

#include "actor.h"

const int MAX_BULLET = 10;

class Bullet : public Actor
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
	Bullet(int posX, int posY, int speedX, int speedY, int radius);
	~Bullet() = default;

	//更新処理
	void Update() override;
	//描画処理
	void Draw() override;
};

#endif // !BULLET_H
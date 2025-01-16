#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"
#include "bullet.h"

class Player : public Actor
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
	Player(int posX, int posY, int speedX, int speedY, int radius);
	~Player() override;

	//更新処理
	void Update() override;
	//描画処理
	void Draw() override;

public:
	Actor* bullet[MAX_BULLET]{};
	int current_bullet;
};

#endif // !PLAYER_H
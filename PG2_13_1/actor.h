#ifndef ACTOR_H
#define ACTOR_H

#include <novice.h>

class Actor
{
public:
	//コンストラクタ引数なし
	Actor() = default;
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">x座標</param>
	/// <param name="posY">y座標</param>
	/// <param name="speedX">速度x</param>
	/// <param name="speedY">速度y</param>
	/// <param name="radius">半径</param>
	Actor(int posX, int posY, int speedX, int speedY, int radius);
	//デストラクタ
	virtual ~Actor() = default;

	//更新処理
	virtual void Update();
	//キー入力結果を受け取る箱
	virtual void Input();
	//描画処理
	virtual void Draw();

public:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	bool isAlive;

	static bool isActive;

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

#endif // !ACTOR_H
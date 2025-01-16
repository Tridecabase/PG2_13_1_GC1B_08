#include "bullet.h"

Bullet::Bullet(int posX, int posY, int speedX, int speedY, int radius)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = radius;
	isAlive = true;
}

void Bullet::Update()
{
	Actor::Update();
	if (posY_ - radius_ <= 0)
	{
		isAlive = false;
	}
}

void Bullet::Draw()
{
	if (isAlive) 
	{
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}

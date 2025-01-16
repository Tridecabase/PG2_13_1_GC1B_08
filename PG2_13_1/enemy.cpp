#include "enemy.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY, int radius)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = radius;
	isAlive = true;
}

void Enemy::Update()
{
	if (isAlive) 
	{
		Actor::Update();
		if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) 
		{
			speedX_ *= -1;
		}
		if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) 
		{
			speedY_ *= -1;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive) 
	{
		Actor::Draw();
	}
}

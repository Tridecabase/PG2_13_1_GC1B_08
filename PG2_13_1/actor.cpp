#include "actor.h"

Actor::Actor(int posX, int posY, int speedX, int speedY, int radius)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = radius;
	isAlive = true;
}

void Actor::Update()
{
	if (isAlive) 
	{
		posX_ -= speedX_;
		posY_ -= speedY_;
	}
}

void Actor::Input()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

void Actor::Draw()
{
	if (isAlive) 
	{
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}

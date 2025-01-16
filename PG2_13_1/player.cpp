#include "player.h"

Player::Player(int posX, int posY, int speedX, int speedY, int radius)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = radius;
	current_bullet = 0;
}

Player::~Player()
{
	for (int i = 0; i < MAX_BULLET; i++) {
		if (bullet[i] != NULL)
		{
			delete bullet[i];
		}
	}
}

void Player::Update()
{
	Actor::Input();
	if (keys[DIK_W] || preKeys[DIK_W])
	{
		posY_ -= speedY_;
	}
	if (keys[DIK_S] || preKeys[DIK_S]) 
	{
		posY_ += speedY_;
	}
	if (keys[DIK_A] || preKeys[DIK_A])
	{
		posX_ -= speedX_;
	}
	if (keys[DIK_D] || preKeys[DIK_D]) 
	{
		posX_ += speedX_;
	}

	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
	{
			if (current_bullet < MAX_BULLET) 
			{
				bullet[current_bullet] = new Bullet(posX_, posY_, 0, 20, 10);
				current_bullet += 1;
			}
			else 
			{
				current_bullet = 0;
				bullet[current_bullet] = new Bullet(posX_, posY_, 0, 20, 10);
				current_bullet += 1;
			}
	}


	for (int i = 0; i < MAX_BULLET; i++) 
	{
		if (bullet[i]) 
		{
			bullet[i]->Update();
		}
	}

}

void Player::Draw()
{
	for (int i = 0; i < MAX_BULLET; i++) 
	{
		if (bullet[i])
		{
			bullet[i]->Draw();
		}
	}
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, GREEN, kFillModeSolid);
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, 0xadff2fff, kFillModeWireFrame);
}
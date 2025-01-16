#ifndef COLLISION_MANAGER
#define COLLISION_MANAGER

#include <math.h>
#include "actor.h"

bool Actor::isActive;

//円と円の当たり判定
void CircleCircle(Actor* c1, Actor* c2) 
{

    int distX = c1->posX_ - c2->posX_;
    int distY = c1->posY_ - c2->posY_;
    float distance = static_cast<float>(sqrt((distX * distX) + (distY * distY)));

    if (distance <= c1->radius_ + c2->radius_) 
    {
        Actor::isActive = false;
    }
}

#endif // !COLLISION_MANAGER
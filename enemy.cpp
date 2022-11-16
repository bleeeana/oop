#include "pch.h"
#include "enemy.h"


float enemy::get_damage()
{
    return this->damage;
}


void enemy::set_speed(float x, float y)
{
    this->speedx = x;
    this->speedy = y;
}

float enemy::get_speedx()
{
    return this->speedx;
}

float enemy::get_speed()
{
    return this->speed;
}

float enemy::get_speedy()
{
    return this->speedy;
}


logoutinfo& enemy::get_info()
{
    return *(this->info);
}

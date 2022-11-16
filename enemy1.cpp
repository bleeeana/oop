#include "pch.h"
#include "enemy1.h"

enemy1::enemy1(logoutinfo* info)
{
	speedx = speedy = 0;
	damage = -1;
	speed = 0.001;
	this->info = info;
}

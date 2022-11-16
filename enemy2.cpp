#include "pch.h"
#include "enemy2.h"

enemy2::enemy2(logoutinfo* info)
{
	speedx = speedy = 0;
	this->info = info;
	this->damage = -5;
	this->speed = 0.00005;
}

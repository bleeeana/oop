#include "pch.h"
#include "enemy3.h"

enemy3::enemy3(logoutinfo* info) {
	this->info = info;
	this->speed = 0.002;
	this->damage = -0.3;
	speedx = speedy = 0;
}
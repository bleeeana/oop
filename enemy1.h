#pragma once
#include "enemy.h"
class enemy1 : public enemy
{
private:
	float speed = 0.0001;
public:
	enemy1(logoutinfo* info = nullptr);
};


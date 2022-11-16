#pragma once
#include "enemy_view.h"
#include "enemy1.h"
class enemy1_view : public enemy_view
{
public:
	enemy1_view(enemy1* enemy, Texture& t, int x, int y);
	~enemy1_view() override
	{
		std::cout << "deleted";
		delete this->en;
	}
	void update(float time, int x) override;
};


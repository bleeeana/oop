#pragma once
#include "enemy_view.h"
#include "enemy2.h"
class enemy2_view : public enemy_view
{
public:
	enemy2_view(enemy2* enemy, Texture& t, int x, int y);
	void update(float time, int x) override;
	~enemy2_view() override
	{
		std::cout << "deleted";

		delete this->en;
	}
};


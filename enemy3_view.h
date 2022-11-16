#pragma once
#include "enemy_view.h"
#include "enemy3.h"
class enemy3_view : public enemy_view
{
public:
	enemy3_view(enemy3* enemy, Texture& t, int x, int y);
	void update(float time, int x) override;
	~enemy3_view() override
	{
		std::cout << "deleted";
		delete this->en;
	}
};


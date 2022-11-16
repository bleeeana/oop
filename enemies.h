#pragma once
#include "enemy_view.h"
#include "enemy1_view.h"
#include "enemy2_view.h"
#include "enemy3_view.h"
#include <vector>
class enemies
{
private:
	std::vector <enemy_view*> enemies;
public:
	~enemies()
	{
		std::cout << "deleted";
		enemies.clear();
	}
	void push_back_new(enemy_view* enemy);
	void movement(int x, player_view* p);
	void attack(player_view* p);
	void draw(RenderWindow& win);
	void update(float time, int x);
};


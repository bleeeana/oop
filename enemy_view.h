#pragma once
#include "enemy.h"
#include "SFML/Graphics.hpp"
#include "player_view.h"
using namespace sf;
class enemy_view
{
protected:
	enemy* en;
	Sprite s;
	float currframe;
public:
	//enemy_view(enemy* enemy, Texture& t, int x, int y);
	virtual void update(float time, int x) = 0;
	virtual ~enemy_view() = 0 {} ;
	void set_speed(float x, float y);
	Sprite& get_s();
	void attack(player_view* p);
	enemy* get_enemy();
};


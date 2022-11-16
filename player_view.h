#pragma once
#include "Player.h"
#include <iostream>
using namespace sf;
class player_view
{
private:
	player* p;
	Sprite s;
	float currframe;
public:
	player_view(player * p, Texture& t);
	~player_view()
	{
	}
	void update(float time, int x);
	player* get_player();	
	Sprite& get_s();
	void draw(RenderWindow& win);
};


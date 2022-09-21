#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using  namespace sf;

class player
{
private:
	
	float speedx,speedy;
	int hp = 100;
	float stamina = 100;
	Sprite s;
	float currframe;
	bool run = 0;
public:
	player(player& pl);
	player(Texture& t);
	void set_speed(float x, float y);
	void update(float time);
	Sprite& get_s();
	void set_run(bool r);
	int get_hp();
	float get_st();
	bool get_r();
	void charging();
	void running();
	int getx();
	int gety();
	float get_sx();
	float get_sy();
};


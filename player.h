#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using  namespace sf;

class player
{
private:
	float speedx,speedy;
	float hp;
	float stamina;
	Sprite s;
	float currframe;
	bool run = 0;
	int counter;
public:
	player(player& pl);
	player(Texture& t, int x, int y, int hp, float stamina);
	void set_speed(float x, float y);
	void update(float time, int x);
	Sprite& get_s();
	void set_run(bool r);
	float get_hp();
	float get_st();
	bool get_r();
	void charging();
	void running();
	int getx();
	int gety();
	float get_sx();
	float get_sy();
	int get_count();
	void set_count();
	void set_hp(float hp);
};


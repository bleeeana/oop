#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class tile 
{
private:
	RectangleShape rect;
	bool is_inside;
	bool is_passable;
	int x, y;
	
public:
	tile(int, int);
	void set_type(bool passable);
	RectangleShape& get_sprite();
	int getx();
	int& gety();
	void react();
	void set_inside(bool in);
	bool get_type();
};


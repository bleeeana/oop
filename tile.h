#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
class tile 
{
private:
	enum type{ cell, wall, heal, hole, treasure, cellinside };
	type t;
	Sprite s;
	Texture t1, t2, t3;
public:
	tile(sf::Texture& t1, sf::Texture& t2, sf::Texture& t3, int, int, int);
	tile(tile& t, int x, int y);
	void set_type(int n);
	Sprite& get_sprite();
	int getx();
	int gety();
	int get_type();
};


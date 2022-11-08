#pragma once
#include <iostream>
#include "cell.h"
#include "SFML/Graphics.hpp"
using namespace sf;
class cell_view
{
private:
	cell* c;
	Sprite s;
public:
	cell_view(cell* c, Texture& t, int x, int y);
	~cell_view()
	{
		c = nullptr;
		delete c;
	}
	Sprite& get_s();
	void set_type(int n);
};


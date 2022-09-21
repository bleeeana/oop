#pragma once
#include "tile.h"
#include <vector>

class mapp
{
private:
	int numx, numy;
	std::vector <std::vector <tile>> tiles;
public:
	mapp(int numx, int numy);
	mapp();
	void initmap();
	int get_numx();
	int get_num_y();
	void drawmap(RenderWindow& win);
	tile& getTiles(int i, int j);
};


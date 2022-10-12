#pragma once
#include "tile.h"
#include <vector>
#include "Source.cpp"

class mapp 
{
private:
	int numx, numy;
	mutable std::vector <std::vector <tile>> tiles;
public:
	mapp(int numx, int numy);
	mapp(mapp& m);
	mapp(mapp&& m);
	mapp();
	void clear();
	mapp operator=(const mapp& m);
	mapp operator=(mapp&& m);
	void initmap();
	int get_numx();
	int get_num_y();
	void drawmap(RenderWindow& win);
	tile& getTiles(int i, int j);
};


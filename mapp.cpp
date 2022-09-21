#include "pch.h"
#include "mapp.h"

mapp::mapp( int numx, int numy)
{
	this->numx = numx;
	this->numy = numy;
	this->initmap();
}

mapp::mapp()
{
	this->numx = 21;
	this->numy = 21;
	this->initmap();
}

void mapp::initmap()
{
	for (size_t i = 0; i < this->numy; i++) {
		this->tiles.push_back(std::vector<tile>());
		for (size_t j = 0; j < this->numx; j++) {
			this->tiles[i].push_back(tile(j * 48, i * 48));
		}
	}
}

int mapp::get_numx()
{
	return this->numx;
}

int mapp::get_num_y()
{
	return this->numy;
}

void mapp::drawmap(RenderWindow& win)
{
	for (int i = 0; i < numy; i++) {
		for (int j = 0; j < numx; j++) {
			if (i == j) tiles[i][j].set_type(0);
			win.draw(tiles[i][j].get_sprite());
		}
	}
}

tile& mapp::getTiles(int i, int j)
{
	return tiles[i][j];
}


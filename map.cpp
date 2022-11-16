#include "pch.h"
#include "Map.h"

Map::Map(int x, int y, logoutinfo* info)
{	
	this->numx = x;
	this->numy = y;
	this->info = info;
}

Map Map::operator=(Map& m)
{
	this->clear();
	this->numy = m.numy;
	this->numx = m.numx;
	for (int i = 0; i <m.numy; i++) {
		this->cells.push_back(std::vector<cell>());
		for (int j = 0; j < m.numx; j++) {
			this->cells[i].push_back(cell(m.get_cur_cell(i, j)));
		}
	}
	return *this;
}

int Map::get_numx() const
{
	return this->numx;
}

int Map::get_numy() const
{
	return this->numy;
}

cell& Map::get_cur_cell(int x, int y)
{
	return cells[x][y];
}

void Map::clear()
{
	numx = NULL;
	numy = NULL;
	cells.clear();
}

void Map::check()
{
	if (this->numx < 0 || this->numy < 0) {
		this->numx = 21;
		this->numy = 21;
		message msg(ERROR, "incorrect data for field", info);
		notify(msg);
	}
	
}

void Map::creat_str()
{
	this->cells.push_back(std::vector<cell>());
}

void Map::creat_elem(int i,cell& c)
{
	this->cells[i].push_back(c);
}

void Map::set_player_location(int x, int y)
{
	if (player_location.first != x || player_location.second != y) {
		message msg(GAME, "player changed location", info);
		notify(msg);
		player_location.first = x;
		player_location.second = y;
	}
}

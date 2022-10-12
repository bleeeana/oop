#include "pch.h"
#include "mapp.h"

mapp::mapp( int numx, int numy)
{
	this->numx = numx;
	this->numy = numy;
	this->initmap();
}

mapp::mapp(mapp& m)
{
	this->numx = m.numx;
	this->numy = m.numy;
	for (size_t i = 0; i < this->numy; i++) {
		this->tiles.push_back(std::vector<tile>());
		for (size_t j = 0; j < this->numx; ++j) {
			this->tiles[i].push_back(tile(m.getTiles(i,j)));
		}
	}
}

mapp::mapp(mapp&& m)
{
	this->numx = m.numx;
	this->numy = m.numy;
	for (size_t i = 0; i < this->numy; i++) {
		this->tiles.push_back(std::vector<tile>());
		for (size_t j = 0; j < this->numx; ++j) {
			this->tiles[i].push_back(tile(m.getTiles(i, j)));
		}
	}
	m.clear();
}



mapp::mapp()
{
	this->numx = 20;
	this->numy = 20;
	this->initmap();
}

void mapp::clear()
{
	this->tiles.clear();
	this->numx = NULL;
	this->numy = NULL;
	
}


mapp mapp::operator=(const mapp& m)
{
	this->clear();
	this->numy = m.numy;
	this->numx = m.numx;
	this->initmap();
	return *this;
}

mapp mapp::operator=(mapp&& m)
{
	this->clear();
	this->numy = m.numy;
	this->numx = m.numx;
	this->initmap();
	m.clear();
	return *this;
	
}

void mapp::initmap()
{
	sf::Texture t1,t2,t3;
	t1.loadFromFile("Gothic.png");
	t2.loadFromFile("Gothic1.png");
	t3.loadFromFile("Gothic (2).png");
	if (numx == 11) {
		for (int i = 0; i < this->numy; i++) {
			this->tiles.push_back(std::vector<tile>());
			for (int j = 0; j < this->numx; j++){ 
				this->tiles[i].push_back(tile(t1,t2,t3, j * 48, i * 48,int(s1[i][j]) - 48));
			}
		}
	}
	else if (numx == 16) {
		for (int i = 0; i < this->numy; i++) {
			this->tiles.push_back(std::vector<tile>());
			for (int j = 0; j < this->numx; j++) {
				this->tiles[i].push_back(tile(t1, t2, t3, j * 48, i * 48, int(s2[i][j])-48));
			}
		}
	}
	else if (numx == 21) {
		for (int i = 0; i < this->numy; i++) {
			this->tiles.push_back(std::vector<tile>());
			for (int j = 0; j < this->numx; j++) {
				this->tiles[i].push_back(tile(t1, t2, t3, j * 48, i * 48, int(s3[i][j])-48));
			}
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
			
			win.draw(tiles[i][j].get_sprite());
		}
		
	}

}

tile& mapp::getTiles(int i, int j)
{
	return tiles[i][j];
}


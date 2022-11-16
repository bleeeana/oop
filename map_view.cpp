#include "pch.h"
#include "Map_view.h"

Map_view::Map_view(Map* m)
{
	this->m = m;

}

void Map_view::drawMap(RenderWindow& win, sf::Texture& t)
{
	for (int i = 0; i < this->m->get_numy(); i++) {
		for (int j = 0; j < this->m->get_numx(); j++) {
			 
			cell_view cw(&this->m->get_cur_cell(i, j), t, j * 48, i * 48);
			win.draw(cw.get_s());
		}

	}
}

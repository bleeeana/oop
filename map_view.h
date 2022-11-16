#pragma once
#include "cell_view.h"
#include "Map.h"
class Map_view
{
private:
	Map* m;
	
public:
	~Map_view()
	{
		delete m;
	}
	Map_view(Map* m);
	void drawMap(RenderWindow& win, sf::Texture& t);
};


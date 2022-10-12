#pragma once
#include "events.h"

class ievent: public events
{
public:
	void game_over(sf::RenderWindow& win, player& pl) override;
	void win(sf::RenderWindow& win, player& pl) override;
};


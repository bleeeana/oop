#pragma once
#include "mapp.h"
#include "player.h"
class events
{
public:
	virtual void give_dmg(player& p);
	virtual void heal(player& p);
	virtual void get_coin(player& p);
	virtual void win(sf::RenderWindow& win, player& pl);
	virtual void game_over(sf::RenderWindow& win, player& pl);
};


#pragma once
#include "player.h"
#include "mapp.h"
class game 
{
private:
	
public:
	void movement(player & pl, mapp& m, sf::Event ev);
	void react(player& pl, mapp& m);
	void collision(player& pl, tile& t, int k);
};


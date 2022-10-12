#pragma once
#include "ievent.h"
#include "nievent.h"
class game 
{
private:
	int n = 0;
public:
	ievent ifev;
	nievent nifev;
	void movement(player & pl, mapp& m, sf::Event ev);
	void react(player& pl, mapp& m);
	void collision(player& pl, tile& t, int k);
};


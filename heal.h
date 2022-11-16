#pragma once
#include "player_events.h"
class heal final: public player_events
{
public:
	heal(player* p);
	void execute(logoutinfo* info) final;
	~heal() final { std::cout << "deleted heal\n"; }
};


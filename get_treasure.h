#pragma once
#include "player_events.h"
class get_treasure final : public player_events
{
public:
	get_treasure(player* p);
	void execute(logoutinfo* info) final;
	~get_treasure() final { std::cout << "deleted getting"; }
};


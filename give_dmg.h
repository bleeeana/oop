#pragma once
#include "player_events.h"
class give_dmg final : public player_events
{
public:
	give_dmg(player* p);
	void execute(logoutinfo* info) final;
};


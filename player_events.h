#pragma once
#include "player.h"
#include "events.h"
class player_events : public events
{
public:
	void execute(logoutinfo* info) override = 0;
	virtual ~player_events() override {};
protected:
	player* p;
};


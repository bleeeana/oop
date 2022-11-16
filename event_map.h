#pragma once
#include "Map.h"
#include "events.h"
#include "player.h"
class event_Map : public events
{
protected:
	Map* m;
	player* p;
public:
	virtual void execute(logoutinfo* info) override = 0;
	virtual ~event_Map() override {}
};


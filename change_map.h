#pragma once
#include "event_Map.h"
class change_Map final: public event_Map
{

public:
	change_Map(Map* m, player* p);
	void execute(logoutinfo* info) final;
};


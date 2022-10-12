#pragma once
#include "events.h"

class nievent : public events
{
public:
	void give_dmg(player& p) override;
	void heal(player& p) override;
	void get_coin(player& p) override;
};


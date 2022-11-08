#pragma once
#include "cell.h"
#include "get_treasure.h"
#include "give_dmg.h"
#include "heal.h"
class cell_facrory
{
public:
	cell* create_new(int type, player* p);
};


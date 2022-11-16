#pragma once
#include "event_Map.h"
#include "cell_facrory.h"
class create_chest : public event_Map
{
public:
	create_chest(Map* m, player* p);
	void execute(logoutinfo* info) final;
	~create_chest() final 
	{
		std::cout<<"deleted creating";
	}
};


#pragma once
#include <iostream>
#include "events.h"
class cell
{
private:
	enum type { empty, wall, healing, hole, treasure, cellinside };
	type t;
	events* event;
public:
	cell(int type, events* event);
	cell(cell* other);
	cell operator=(cell& c);
	~cell(){}
	void set_type(int type);
	int get_type();
	void get_event(logoutinfo* info);
	void delete_event();
};


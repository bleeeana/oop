#include "pch.h"
#include "get_treasure.h"

get_treasure::get_treasure(player* p)
{
	this->p = p;
	this->add_observer(new iobserver());

}

void get_treasure::execute(logoutinfo* info)
{
	this->p->set_counter();
	message msg(GAME, "treasure event", info);
	notify(msg);
}
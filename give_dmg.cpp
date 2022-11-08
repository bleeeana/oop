#include "pch.h"
#include "give_dmg.h"

give_dmg::give_dmg(player* p)
{
	this->add_observer(new iobserver());
	this->p = p;
}

void give_dmg::execute(logoutinfo* info)
{
	if (p->get_hp() >= 50) p->set_hp(-50);
	else p->set_hp(-p->get_hp());
	message msg(GAME, "damage event", info);
	notify(msg);
}



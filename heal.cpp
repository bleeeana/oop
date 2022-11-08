#include "pch.h"
#include "heal.h"

heal::heal(player* p)
{

	this->p = p;
	this->add_observer(new iobserver());

}

void heal::execute(logoutinfo* info)
{
	if (100 - p->get_hp() >= 20)
		this->p->set_hp(20);
	else this->p->set_hp(100 - p->get_hp());
	message message(GAME, "heal event", info);
	notify(message);
}


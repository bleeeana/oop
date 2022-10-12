#include "pch.h"
#include "nievent.h"

void nievent::give_dmg(player& p)
{
	p.set_hp(-50);
}

void nievent::heal(player& p)
{
	p.set_hp(10);
}

void nievent::get_coin(player& p)
{
	p.set_count();
	std::cout << p.get_count();
}

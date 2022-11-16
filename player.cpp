#include "pch.h"
#include "player.h"

player::player(logoutinfo* info)
{
	this->info = info;
	this->speedx = 0;
	this->speedy = 0;
	this->stamina = 100;
	this->hp = 100;
	this->counter = 0;
}

void player::set_speed(long double x, long double y)
{
	this->speedx = x;
	this->speedy = y;
}

void player::set_hp(float hp)
{
	this->hp += hp;
	
}

void player::set_run(bool r)
{
	if (r) {
		message msg(GAME, "player started to run", info);
		notify(msg);
	}
	else {
		message msg(GAME, "player finished to run", info);
		notify(msg);
	}
	this->run = r;
	
}

bool player::get_run()
{
	return this->run;
}

void player::charging()
{
	if (stamina < 100 && !run) {
		stamina += 0.334;
	}
}

void player::running()
{
	if (run && stamina > 0) {
		stamina -= 0.668;
	}
	if (stamina <= 0) {
		run = 0;
	}
}

int player::get_hp()
{
	return this->hp;
}

int player::get_stamina()
{
	return this->stamina;
}

int player::get_counter()
{
	return this->counter;
}

long double player::get_speedx()
{
	return this->speedx;
}

long double player::get_speedy()
{
	return this->speedy;
}

void player::set_counter()
{
	
	this->counter += 1;
}

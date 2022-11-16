#include "pch.h"
#include "enemy_view.h"



void enemy_view::update(float time, int x)
{
	
}

void enemy_view::set_speed(float x, float y)
{
	this->en->set_speed(x, y);
}

Sprite& enemy_view::get_s()
{
	return this->s;
}

void enemy_view::attack(player_view* p)
{
	if ( fabs(p->get_s().getPosition().x - s.getPosition().x) < 70 && fabs(p->get_s().getPosition().y - s.getPosition().y) < 45) {
		p->get_player()->set_hp(this->en->get_damage());
		std::cout << "attack";
		message msg(GAME, "enemy gived damage", &en->get_info());
		this->en->notify(msg);
	}
}

enemy* enemy_view::get_enemy()
{
	return this->en;
}

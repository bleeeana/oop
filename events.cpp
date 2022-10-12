#include "pch.h"
#include "events.h"

void events::give_dmg(player& p)
{
	p.set_hp(-0.01);
}

void events::heal(player& p)
{

}

void events::get_coin(player& p)
{
}

void events::win(sf::RenderWindow& win, player& pl)
{
}

void events::game_over(sf::RenderWindow& win, player& pl)
{

}

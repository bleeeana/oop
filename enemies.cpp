#include "pch.h"
#include "enemies.h"

void enemies::push_back_new(enemy_view* enemy)
{
	this->enemies.push_back(enemy);
	this->enemies.back()->get_enemy()->add_observer(new iobserver);
	
}

void enemies::movement(int x, player_view* p)
{

	for (int i = 0; i < enemies.size(); i++) {
		if (abs(p->get_s().getPosition().x - enemies[i]->get_s().getPosition().x) < x * 48 / 5 && (abs(p->get_s().getPosition().y - enemies[i]->get_s().getPosition().y)) < x * 48 / 5) {
			float speedx = long double((abs(p->get_s().getPosition().x - enemies[i]->get_s().getPosition().x) / float(p->get_s().getPosition().x - enemies[i]->get_s().getPosition().x + 0.000000000001))) * 0.0001;
			float speedy = long double((abs(p->get_s().getPosition().y - enemies[i]->get_s().getPosition().y) / float(p->get_s().getPosition().y - enemies[i]->get_s().getPosition().y + 0.000000000001))) * 0.0001;
			//std::cout << speedx << " " << speedy << '\n';
			enemies[i]->set_speed(speedx, speedy);
		}
		else enemies[i]->set_speed(0.0001, 0);
	}
}

void enemies::attack(player_view* p)
{
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->attack(p);
	}
}

void enemies::draw(RenderWindow& win)
{
	for (int i = 0; i < enemies.size(); i++) {
		win.draw(enemies[i]->get_s());
	}
}

void enemies::update(float time, int x)
{
	for(int i = 0; i < enemies.size(); i++) {
		enemies[i]->update(time, x);
	}
}

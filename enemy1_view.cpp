#include "pch.h"
#include "enemy1_view.h"

enemy1_view::enemy1_view(enemy1* enemy, Texture& t, int x, int y)
{
	this->en = enemy;
	s.setTexture(t);
	s.setPosition(x, y);
	s.setTextureRect(IntRect(288, 96, 47, 47));
	s.setOrigin(24, 24);
	this->currframe = 0;
}

void enemy1_view::update(float time, int x)
{
	s.setPosition((int(s.getPosition().x) + (x - 1) * 48) % ((x - 1) * 48), (int(s.getPosition().y) + (x - 1) * 48) % ((x - 1) * 48));
	s.move(this->en->get_speedx() * time, this->en->get_speedy() * time);
	currframe += 0.00001 * time;
	if (currframe > 3) currframe -= 3;
	if (this->en->get_speedx() > 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 96, 47, 47));
	if (this->en->get_speedy() < 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 145, 47, 47));
	if (this->en->get_speedx() < 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 48, 47, 47));
	if (this->en->get_speedy() > 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 2, 47, 47));
	en->set_speed(0, 0);
}

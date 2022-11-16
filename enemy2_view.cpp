#include "pch.h"
#include "enemy2_view.h"

enemy2_view::enemy2_view(enemy2* enemy, Texture& t, int x, int y)
{
	this->en = enemy;
	s.setTexture(t);
	s.setPosition(x, y);
	s.setTextureRect(IntRect(288, 194, 47, 47));
	s.setOrigin(24, 24);
	this->currframe = 0;
}

void enemy2_view::update(float time, int x)
{
	s.setPosition((int(s.getPosition().x) + (x - 1) * 48) % ((x - 1) * 48), (int(s.getPosition().y) + (x - 1) * 48) % ((x - 1) * 48));
	s.move(this->en->get_speedx() * time, this->en->get_speedy() * time);
	currframe += 0.00001 * time;
	if (currframe > 3) currframe -= 3;
	if (this->en->get_speedx() > 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 292, 47, 47));
	if (this->en->get_speedy() < 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 341, 47, 47));
	if (this->en->get_speedx() < 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 243, 47, 47));
	if (this->en->get_speedy() > 0) this->s.setTextureRect(IntRect(288 + 50 * int(currframe), 194, 47, 47));
	en->set_speed(0, 0);
}

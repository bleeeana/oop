#include "pch.h"
#include "player_view.h"

player_view::player_view(player* p, Texture& t)
{
	this->p = p;
	s.setTexture(t);
	s.setPosition(100,100);
	s.setTextureRect(IntRect(164, 40, 58, 97));
	s.setOrigin(30, 90);
	this->currframe = 0;
}

void player_view::update(float time, int x)
{
	s.setPosition((int(s.getPosition().x) + (x-1) * 48) % ((x-1) * 48), (int(s.getPosition().y) + (x-1) * 48) % ((x-1) * 48));
	s.move(this->p->get_speedx() * time, this->p->get_speedy() * time);
	currframe += 0.00001 * time;
	if (currframe > 5) { currframe -= 5; }
	
	if (this->p->get_speedx() > 0) {
		s.setTextureRect(IntRect(164 + 120 * int(currframe), 404, 54, 91)); p->running();
	}
	if (this->p->get_speedy() > 0) {
		s.setTextureRect(IntRect(155 + 120 * int(currframe), 282, 67, 95)); p->running();
	}
	if (this->p->get_speedy() < 0) {
		s.setTextureRect(IntRect(164 + 120 * int(currframe), 40, 58, 97)); p->running();
	}
	if (this->p->get_speedx() < 0) {
		s.setTextureRect(IntRect(160 + 121 * int(currframe), 164, 69, 91)); p->running();
	}
	p->charging();
	p->set_speed(0, 0);
	
}

player* player_view::get_player()
{
	return this->p;
}

Sprite& player_view::get_s()
{
	return this->s;
}

void player_view::draw(RenderWindow& win)
{
	RectangleShape h(sf::Vector2f(p->get_hp(), 20));
	RectangleShape st(sf::Vector2f(p->get_stamina(), 10));
	st.setPosition(0, 24);
	st.setFillColor(Color::Blue);
	h.setPosition(0, 0);
	h.setFillColor(Color::Red);
	win.draw(h);
	win.draw(st);
	win.draw(this->s);
	
}

#include "pch.h"
#include "player.h"

player::player(player& pl)
{
	this->hp = pl.get_hp();
	this->s = pl.get_s();
	this->stamina = pl.get_st();
	this->counter = 0;

}

player::player(Texture& t, int x, int y, int hp, float stamina)
{
	s.setTexture(t);
	s.setPosition(x, y);
	s.setTextureRect(IntRect(164, 40, 58, 97));
	s.setOrigin(30, 90);
	speedx = speedy = 0;
	currframe = 0;
	this->hp = hp;
	this->stamina = stamina;
	this->counter = 0;
}


void player::set_speed(float x, float y)
{
	this->speedx = x;
	this->speedy = y;
}



void player::update(float time, int x) {
	
	s.setPosition((int(s.getPosition().x)+x*48) % (x * 48),(int(s.getPosition().y)+ x * 48) % (x * 48));
	s.move(speedx * time, speedy * time);
	currframe += 0.00001 * time;
	if (currframe > 5) currframe -= 5;
	if (speedx < 0) { s.setTextureRect(IntRect(160 + 121 * int(currframe), 164, 69, 91)); running(); 
	}
	if (speedx > 0) { s.setTextureRect(IntRect(164 + 120 * int(currframe), 404, 54, 91)); running(); 
	}
	if (speedy > 0) { s.setTextureRect(IntRect(155 + 120 * int(currframe), 282, 67, 95)); running(); 
	}
	if (speedy < 0) { s.setTextureRect(IntRect(164 + 120 * int(currframe), 40, 58, 97)); running();
	}
	charging();
	speedx = 0;
	speedy = 0;
	
}

Sprite& player::get_s()
{
	return s;
}

void player::set_run(bool r)
{
	this->run = r;
}

float player::get_hp()
{
	return this->hp;
}

float player::get_st()
{
	return int(this->stamina);
}

bool player::get_r()
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
	if (run && stamina>0) {
		stamina -= 0.668;
	}
	if (stamina <= 0) {
		run = 0;
	}
}

int player::getx()
{
	return this->s.getPosition().x;
}

int player::gety()
{
	return this->s.getPosition().y;
}

float player::get_sx()
{
	return speedx;
}

float player::get_sy()
{
	return speedy;
}

int player::get_count()
{
	return counter;
}

void player::set_count()
{
	this -> counter++;
}

void player::set_hp(float hp)
{
	this->hp += hp;
}




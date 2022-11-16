#pragma once
#include "SFML/Graphics.hpp"
#include "iobservable.h"
class player : public iobservable
{
private:
	long double speedx, speedy;
	float hp;
	float stamina;
	bool run = 0;
	int counter;
	logoutinfo* info;
public:
	~player()
	{
		delete info;
	}
	player(logoutinfo* info = nullptr);
	void set_speed(long double x, long double y);
	void set_hp(float hp);
	void set_run(bool r);
	bool get_run();
	void charging();
	void running();
	int get_hp();
	int get_stamina();
	int get_counter();
	long double get_speedx();
	long double get_speedy();
	void set_counter(); // пусть оно еще и на экран выводится
};


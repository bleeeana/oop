#pragma once
#include "iobservable.h"
class enemy : public iobservable
{
protected:
	float speed;
	float damage;
	float speedx, speedy;
	logoutinfo* info;
public:
	float get_damage();
	void set_speed(float x,float y);
	float get_speedx();
	float get_speed();
	float get_speedy();
	logoutinfo& get_info();
};


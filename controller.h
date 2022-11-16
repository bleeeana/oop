#pragma once
#include "Map_view.h"
#include "fieldfactory.h"
#include "change_Map.h"
#include "create_chest.h"
#include "iobservable.h"
#include "enemies.h"
class controller : public iobservable
{
private:
	player* pl;
	player_view* p;
	Map* field;
	Map_view* field_view;
	logoutinfo* info;
	int progress = 0;
	enemies* enemy;
public: 
	controller(player* p, player_view& pv, Map* m, Map_view& mv, enemies* enemies, logoutinfo* info = nullptr);
	void set_Map();
	Map* get_field();
	void set_enemies(int k, Texture& t);
	~controller()
	{
		delete pl, field, p, field_view, info;
	}
	void set_levels(int k);
	void movement(int k);
	void enemy_action();
	void change();
	void react();
	void draw(sf::RenderWindow& win, sf::Texture& t, float time);
	void colission(int i, int j, int k);
	bool lose();
	bool win();
	void enemy_movement();
	
};


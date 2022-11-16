#pragma once
#include "Map_view.h"
#include "player_view.h"
#include "fieldfactory.h"
#include "change_Map.h"
#include "create_chest.h"
#include "iobservable.h"
class controller : public iobservable
{
private:
	player* pl;
	player_view* p;
	Map* field;
	Map_view* field_view;
	logoutinfo* info;
	int progress = 0;
public: 
	controller(player* p, player_view& pv, Map* m, Map_view& mv, logoutinfo* info = nullptr);
	void set_Map();
	Map* get_field();
	~controller()
	{delete pl, field, p, field_view, info;}
	void set_levels(int k);
	void movement(int k);
	void change();
	void react();
	void draw(sf::RenderWindow& win, sf::Texture& t, float time);
	void colission(int i, int j, int k);
	bool lose();
	bool win();

};


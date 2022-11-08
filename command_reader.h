#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "iobservable.h"
#include "gui_management.h"
//#include "console_management.h"
using namespace sf;
class command_reader : public iobservable
{
private:
	int height;
	int width;
	sf::Event event;
	std::vector <OUTPUT> outputs;
	std::vector <LEVEL> levels;
	sfml_configuration* cfg;
	management* mng;
public:
	void set_settings();
	void input_size_win();
	int input_event();
	//void set_management();
	sf::Event& get_event();
	int get_w();
	int get_h();
	void win_screen(RenderWindow& win);
	void lose_screen(RenderWindow& win);
	void set_output();
	std::vector <OUTPUT> command_reader::get_outputs();
	std::vector <LEVEL> command_reader::get_levels();
	void set_levels();
};


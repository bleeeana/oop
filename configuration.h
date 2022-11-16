#pragma once
#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
class configuration
{
public:
	enum setting { UP, DOWN, LEFT, RIGHT, RUN, QUIT };
	virtual void input(setting type, std::string b) = 0;
	virtual int input_commands(sf::Event& event) = 0;
	virtual void check() = 0;
};


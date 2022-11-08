#pragma once
#include <fstream>
#include "key.h"
#include "configuration.h"
class sfml_configuration : public configuration
{
public:
	enum setting {UP, DOWN, LEFT, RIGHT,RUN};
	sfml_configuration();
	~sfml_configuration(){}
	std::map<setting, sf::Keyboard::Key> config;
	virtual void input() override = 0;
};


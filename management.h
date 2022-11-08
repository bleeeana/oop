#pragma once
#include "input_config.h"
#include "input_config_console.h"
class management
{
public:
	virtual int input_commands(sfml_configuration& cfg, sf::Event& event) = 0;
};


#pragma once
#include "management.h"
class gui_management  final: public management
{
	int input_commands(sfml_configuration& cfg, sf::Event& event) final;
};


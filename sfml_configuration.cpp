#include "pch.h"

#include "sfml_configuration.h"

sfml_configuration::sfml_configuration()
{
	if (this->config.empty()) {
		this->config.insert({ UP, sf::Keyboard::Key::W });
		this->config.insert({ DOWN, sf::Keyboard::Key::S });
		this->config.insert({ LEFT, sf::Keyboard::Key::A });
		this->config.insert({ RIGHT, sf::Keyboard::Key::D });
		this->config.insert({ RUN, sf::Keyboard::Key::LShift });
	}
}



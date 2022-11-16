#pragma once
#include <fstream>
#include "key.h"
#include "configuration.h"
class sfml_configuration : public configuration
{
private:
	std::map<setting, sf::Keyboard::Key> config;
public:
	sfml_configuration();
	~sfml_configuration() {};
	void input(setting type, std::string b) override;
	int input_commands(sf::Event& event) override;
	void check() override;
};


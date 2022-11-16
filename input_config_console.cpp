#include "pch.h"
#include "input_config_console.h"



input_config_console::input_config_console(configuration* cfg)
{
	this->cfg = cfg;
}

void input_config_console::set()
{
	std::string s, b;
	while (s != "end") {
		getline(std::cin, s);
		getline(std::cin, b);
		if (s == "UP") {
			this->cfg->input(configuration::setting::UP, b);
		}
		else if (s == "DOWN") {
			this->cfg->input(configuration::setting::DOWN, b);
		}
		else if (s == "LEFT") {
			this->cfg->input(configuration::setting::LEFT, b);
		}
		else if (s == "RIGHT") {
			this->cfg->input(configuration::setting::RIGHT, b);
		}
		else if (s == "RUN") {
			this->cfg->input(configuration::setting::RUN, b);
		}
		else if (s == "QUIT") {
			this->cfg->input(configuration::setting::QUIT, b);
		}
	}
}

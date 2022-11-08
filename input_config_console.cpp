#include "pch.h"
#include "input_config_console.h"

void input_config_console::input()
{
	config.clear();
	for (int i = 0; i < 5; i++) {
		std::string s;
		getline(std::cin, s);
		std::string b;
		getline(std::cin, b);
		if (s == "UP") {
			config.insert({ UP,key::get_instance()->get_keys()->at(b) });
		}
		else if (s == "DOWN") {
			config.insert({ DOWN, key::get_instance()->get_keys()->at(b) });
		}
		else if (s == "LEFT") {
			config.insert({ LEFT, key::get_instance()->get_keys()->at(b) });
		}
		else if (s == "RIGHT") {
			config.insert({ RIGHT, key::get_instance()->get_keys()->at(b) });
		}
		else if (s == "RUN") {
			config.insert({ RUN, key::get_instance()->get_keys()->at(b) });
		}
		else {
			std::cout << "WTF man";
			i--;
		}
	}
}

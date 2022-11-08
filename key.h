#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
class key
{
private: 
	std::map<std::string, sf::Keyboard::Key> set_key;
	static key* instance;
	key();
public:
	key(const key&) = delete;
	void operator=(const key&) = delete;
	std::map<std::string, sf::Keyboard::Key>* get_keys();
	static key* get_instance();
	void select_data();
};


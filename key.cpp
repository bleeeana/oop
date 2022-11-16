#include "pch.h"
#include "key.h"
key::key() {
	
}


void key::delete_key()
{
	delete instance;
}

std::map<std::string, sf::Keyboard::Key>* key::get_keys()
{
	return &set_key;
}

key* key::get_instance() {
	if (instance == nullptr) {
		instance = new key();
	}
	return instance;
}

void key::select_data()
{
	this->set_key = std::map<std::string, sf::Keyboard::Key>({
		{"a",sf::Keyboard::A},
		{"b",sf::Keyboard::B},
		{"c",sf::Keyboard::C},
		{"d",sf::Keyboard::D},
		{"e",sf::Keyboard::E},
		{"f",sf::Keyboard::F},
		{"g",sf::Keyboard::G},
		{"h",sf::Keyboard::H},
		{"i",sf::Keyboard::I},
		{"j",sf::Keyboard::J},
		{"k",sf::Keyboard::K},
		{"l",sf::Keyboard::L},
		{"m",sf::Keyboard::M},
		{"n",sf::Keyboard::N},
		{"o",sf::Keyboard::O},
		{"p",sf::Keyboard::P},
		{"q",sf::Keyboard::Q},
		{"r",sf::Keyboard::R},
		{"s",sf::Keyboard::S},
		{"t",sf::Keyboard::T},
		{"u",sf::Keyboard::U},
		{"v",sf::Keyboard::V},
		{"w",sf::Keyboard::W},
		{"x",sf::Keyboard::X},
		{"y",sf::Keyboard::Y},
		{"z",sf::Keyboard::Z},
		{"shift",sf::Keyboard::LShift},
		{"alt",sf::Keyboard::LAlt},
		{"up",sf::Keyboard::Up},
		{"down",sf::Keyboard::Down},
		{"left",sf::Keyboard::Left},
		{"right",sf::Keyboard::Right},
		{"alt", sf::Keyboard::LAlt},
		{"esc", sf::Keyboard::Escape}
		}
	);
}

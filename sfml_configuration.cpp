#include "pch.h"
#include <string>
#include "sfml_configuration.h"

sfml_configuration::sfml_configuration()
{
	
}

void sfml_configuration::input(setting type, std::string b)
{
	this->config.insert({type, key::get_instance()->get_keys()->at(b) });
}

int sfml_configuration::input_commands(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == config.at(sfml_configuration::setting::RUN)) {
            return -1;
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == config.at(sfml_configuration::setting::RUN)) {
            return -2;
        }
        else return 4;
    }
    if (sf::Keyboard::isKeyPressed(config.at(sfml_configuration::setting::UP))) {
        return 0;
    }
    if (sf::Keyboard::isKeyPressed(config.at(sfml_configuration::setting::DOWN))) {
        return 1;
    }
    if (sf::Keyboard::isKeyPressed(config.at(sfml_configuration::setting::LEFT))) {
        return 2;
    }
    if (sf::Keyboard::isKeyPressed(config.at(sfml_configuration::setting::RIGHT))) {
        return 3;
    }
    if (sf::Keyboard::isKeyPressed(config.at(sfml_configuration::setting::QUIT))) {
        return 5;
        
    }
    return 4;
}

void sfml_configuration::check()
{
    
    if (config.empty()) {
        this->config.insert({ UP,  key::get_instance()->get_keys()->at("w") });
        this->config.insert({ DOWN,  key::get_instance()->get_keys()->at("s") });
        this->config.insert({ LEFT,  key::get_instance()->get_keys()->at("a") });
        this->config.insert({ RIGHT,  key::get_instance()->get_keys()->at("d") });
        this->config.insert({ RUN,  key::get_instance()->get_keys()->at("shift") });
        this->config.insert({ QUIT, key::get_instance()->get_keys()->at("esc") });
    }
    for (int i = 0; i < config.size();) {
        if (config.count(UP)!= NULL) i++;
        else this->config.insert({ UP,  key::get_instance()->get_keys()->at("w") });
        if (config.count(DOWN) != NULL) i++;
        else this->config.insert({ DOWN,  key::get_instance()->get_keys()->at("s") });
        if (config.count(LEFT) != NULL) i++;
        else this->config.insert({ LEFT,  key::get_instance()->get_keys()->at("a") });
        if (config.count(RIGHT) != NULL) i++;
        else this->config.insert({ RIGHT,  key::get_instance()->get_keys()->at("d") });
        if (config.count(RUN) != NULL) i++;
        else this->config.insert({ RUN,  key::get_instance()->get_keys()->at("shift") });
        if (config.count(QUIT) != NULL) i++;
        else this->config.insert({ QUIT, key::get_instance()->get_keys()->at("esc") });
    }
}






#include "pch.h"
#include "gui_management.h"

int gui_management::input_commands(sfml_configuration& cfg, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == cfg.config.at(sfml_configuration::setting::RUN)) {
            return -1;
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == cfg.config.at(sfml_configuration::setting::RUN)) {
            return -2;
        }
        else return 4;
    }
    if (sf::Keyboard::isKeyPressed(cfg.config.at(sfml_configuration::setting::UP))) {
        return 0;
    }
    if (sf::Keyboard::isKeyPressed(cfg.config.at(sfml_configuration::setting::DOWN))) {
        return 1;
    }
    if (sf::Keyboard::isKeyPressed(cfg.config.at(sfml_configuration::setting::LEFT))) {
        return 2;
    }
    if (sf::Keyboard::isKeyPressed(cfg.config.at(sfml_configuration::setting::RIGHT))) {
        return 3;
    }
    return 4;
}

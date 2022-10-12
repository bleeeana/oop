#include "pch.h"
#include "ievent.h"

void ievent::game_over(sf::RenderWindow& win, player& pl)
{
    if (pl.get_hp() <= 0) {
        win.close();
        sf::RenderWindow window(sf::VideoMode(500, 200), "Game over");
        sf::Text message;
        sf::Font font;
        font.loadFromFile("Beat My Guest.ttf");
        message.setFont(font);
        message.setString("Game over(");
        message.setCharacterSize(100);
        message.setFillColor(sf::Color::Red);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(message);
            window.display();
        }
    }
}


void ievent::win(sf::RenderWindow& win, player& pl)
{
    if (pl.get_count() == 3)  {
        win.close();
        sf::RenderWindow window(sf::VideoMode(500, 250), "WIN");
        sf::Text message;
        sf::Font font;
        font.loadFromFile("Beat My Guest.ttf");
        message.setFont(font);
        message.setString("W I N)");
        message.setCharacterSize(200);
        message.setFillColor(sf::Color::Red);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(message);
            window.display();
        }
    }
}

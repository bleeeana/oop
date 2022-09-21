#include "pch.h"
#include "tile.h"



tile::tile(int x, int y): x(x), y(y)
{
    
    this->is_passable = 1;
    this->is_inside = 0;
    this->rect.setSize(sf::Vector2f(48,48));
    this->rect.setFillColor(Color::White);
    this->rect.setOutlineThickness(4);
    this->rect.setOutlineColor(Color::Black);
    this->rect.setPosition(this->x, this->y);
    this->rect.setOrigin(24, 24);
}

void tile::set_type(bool passable)
{
    is_passable = passable;
}



RectangleShape& tile::get_sprite()
{
    return this->rect;
}

int tile::getx()
{
    return this->x;
}

int& tile::gety()
{
    return this->y;

}


void tile::react()
{
    if (!is_passable) this->rect.setFillColor(Color::Yellow);
    else {
        if (is_inside) {
            this->rect.setFillColor(Color::Red);
        }
        else this->rect.setFillColor(Color::White);
    }
}

void tile::set_inside(bool in)
{
    is_inside = in;
}

bool tile::get_type()
{
    return this->is_passable;
}


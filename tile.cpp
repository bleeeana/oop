#include "pch.h"
#include "tile.h"



tile::tile( sf::Texture& t1, sf::Texture& t2, sf::Texture& t3, int x, int y, int type)
{
    this->t1 = t1;
    this->t2 = t2;
    this->t3 = t3;
    this->set_type(type);
    s.setOrigin(24, 24);
    s.setPosition(x, y);
}

tile::tile(tile& t, int x, int y)
{
    this->t1 = t.t1;
    this->t2 = t.t2;
    this->t3 = t.t3;
    this->set_type(t.get_type());
    s.setOrigin(24, 24);
    this->s.setPosition(x, y);  
}

void tile::set_type(int n)
{
    switch (n) {
    case 0:
       t = type::cell;
       s.setTexture(t2);  
       s.setTextureRect(IntRect(480, 335, 48, 48)); 
       break;
    case 1:
        t = type::wall;
        s.setTexture(t2);
        s.setTextureRect(IntRect(434, 434, 48, 48)); 
        break;
    case 2:
        t = type::heal;
        s.setTexture(t3);
        s.setTextureRect(IntRect(434, 720, 48, 48)); 
        break;
    case 3:
        t = type::hole;
        s.setTexture(t3);
        s.setTextureRect(IntRect(243, 548, 48, 48)); 
        break;
    case 4:
        t = type::treasure;
        s.setTexture(t3);
        s.setTextureRect(IntRect(528, 335, 48, 48)); 
        break;
    case 5:
        t = type::cellinside;
        this->s.setTexture(t1);
        this->s.setTextureRect(IntRect(480, 335, 48, 48));
        break;
    default:
        t = type::wall;
        s.setTexture(t2);
        s.setTextureRect(IntRect(434, 434, 48, 48));
        break;
    }
}



Sprite& tile::get_sprite()
{
    return this->s;
}

int tile::getx()
{
    return this->s.getPosition().x;
}

int tile::gety()
{
    return this->s.getPosition().y;

}



int tile::get_type()
{
    if (this->t == type::cell) {
        return 0;
    }
    else if (this->t == type::wall) {
        return 1;
    }
    else if (this->t == type::heal) {
        return 2;
    }
    else if (this->t == type::hole) {
        return 3;
    }
    else if (this->t == type::treasure) {
        return 4;
    }
    else if (this->t == type::cellinside) {
        return 5;
    }
}




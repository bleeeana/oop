#include "pch.h"
#include "cell_view.h"

cell_view::cell_view(cell* c, Texture& t, int x, int y)
{
    this->s.setTexture(t);
    this->c = c;
    switch (this->c->get_type()) {
    case 0:
        s.setTextureRect(IntRect(432, 335, 48, 48));
        break;
    case 1:
        s.setTextureRect(IntRect(434, 434, 48, 48));
        break;
    case 2:
        s.setTextureRect(IntRect(434, 720, 48, 48));
        break;
    case 3:
        s.setTextureRect(IntRect(243, 548, 48, 48));
        break;
    case 4:
        s.setTextureRect(IntRect(528, 335, 48, 48));
        break;
    case 5:
        s.setTextureRect(IntRect(480, 335, 48, 48));
        break;
    default:
        s.setTextureRect(IntRect(432, 335, 48, 48));
        break;
    }
    s.setOrigin(24, 24);
    s.setPosition(x, y);
}


Sprite& cell_view::get_s()
{
	return this->s;
}

void cell_view::set_type(int n)
{
    this->c->set_type(n);
}

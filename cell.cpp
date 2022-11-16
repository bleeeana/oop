#include "pch.h"
#include "cell.h"
#include "logoutinfo.h"

cell::cell(int type, events* event)
{
	set_type(type);
    this->event = event;
}

cell::cell(cell* other)
{
    this->set_type(other->get_type());
    this->event = other->event;
}

cell cell::operator=(cell& c)
{
    this->t = c.t;
    this->event = c.event;
    return *this;
}



void cell::set_type(int type)
{
    switch (type) {
    case 0:
        t = type::empty;
        break;
    case 1:
        t = type::wall;
        break;
    case 2:
        t = type::healing;
        break;
    case 3:
        t = type::hole;
        break;
    case 4:
        t = type::treasure;
        break;
    case 5:
        t = type::cellinside;
        break;
    default:
        t = type::wall;
        break;
    }
}

int cell::get_type()
{
    if (this->t == type::empty) {
        return 0;
    }
    else if (this->t == type::wall) {
        return 1;
    }
    else if (this->t == type::healing) {
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

void cell::get_event(logoutinfo* info)
{
    if (this->event != nullptr) this->event->execute(info);
    delete_event();
}

void cell::delete_event()
{
    delete event;
    event = nullptr;
    
}



#include "pch.h"
#include "iobservable.h"
#include <algorithm>

void iobservable::add_observer(iobserver* o)
{
	observers.push_back(o);
}

void iobservable::remove_observer(iobserver* o)
{
	std::remove(observers.begin(),observers.end(), o);
}

void iobservable::notify(message& msg)
{
	for (auto elem : msg.get_info()->get_levels()) {
		if (elem == msg.getType()) {
			this->observers.back()->update(msg);
			break;
		}
	}
		
}

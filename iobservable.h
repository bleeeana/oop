#pragma once
#include "iobserver.h"
#include "message.h"
#include <vector>
#include <algorithm>
class iobservable
{
private:
	std::vector <iobserver*> observers;
public:
	void add_observer(iobserver* o);
	void remove_observer(iobserver* o);
	void notify(message& msg);
};


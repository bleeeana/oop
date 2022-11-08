#pragma once
#include "iobservable.h"
class events : public iobservable
{
public:
	virtual void execute(logoutinfo* info) = 0;
};


#pragma once
#include "message.h"

class output
{
public:
	virtual ~output() = default;
	virtual void print(message & message) = 0;
};


#pragma once
#include <iostream>
#include "logger.h"
class iobserver
{
public:
	void update(message& msg);
};


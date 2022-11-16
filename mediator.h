#pragma once
#include "command_reader.h"
#include "controller.h"
class mediator
{
private:
	command_reader* reader;
	controller* control;
public:
	mediator(controller& control, command_reader& com);
	void start();
};


#pragma once
#include "input.h"
class input_config_console : public input
{
private:
	configuration* cfg;
public:
	input_config_console(configuration* cfg);
	void set() override;
};


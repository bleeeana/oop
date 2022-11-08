#pragma once
#include "sfml_configuration.h"
class input_config_console final: public sfml_configuration // iobservable
{
public:
	void input() final;
};


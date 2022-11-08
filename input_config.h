#pragma once
#include "sfml_configuration.h"
using namespace std;
class input_config final : public sfml_configuration
{
public:
	void input() override;
};


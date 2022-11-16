#pragma once
#include "input.h"
using namespace std;
class input_config : public input
{
private:
	configuration* cfg;
public:
	input_config(configuration* cfg);
	void set() override;
};


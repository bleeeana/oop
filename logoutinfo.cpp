#include "pch.h"
#include "logoutinfo.h"

logoutinfo::logoutinfo(std::vector<OUTPUT> outputs, std::vector<LEVEL> levels)
{
	this->outputs = outputs;
	this->levels = levels;
}

std::vector<LEVEL>& logoutinfo::get_levels()
{
	return this->levels;
}

std::vector<OUTPUT>& logoutinfo::get_outputs()
{
	return this->outputs;
}

void logoutinfo::set_levels(std::vector<LEVEL> levels)
{
	this->levels = levels;
}

void logoutinfo::set_outputs(std::vector<OUTPUT> outputs)
{
	this->outputs = outputs;
}

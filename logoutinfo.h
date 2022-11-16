#pragma once
#include "logs.h"
#include <vector>
#include <string>
#include <iostream>
class logoutinfo
{
public:
    logoutinfo(std::vector <OUTPUT> outputs, std::vector <LEVEL> levels);
    std::vector <LEVEL>& get_levels();
    std::vector <OUTPUT>& get_outputs();
    void set_levels(std::vector<LEVEL> levels);
    void set_outputs(std::vector<OUTPUT> outputs);
private:
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
};


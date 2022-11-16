#pragma once
#include "output.h"
#include <fstream>
class fileoutput : public output
{
public:
    fileoutput(std::string name);
    ~fileoutput();
    void print(message& message) override;

private:
    std::ofstream file;
};


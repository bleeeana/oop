#pragma once
#include "output.h"
#include <iostream>
class consoleoutput : public output
{
public:
    void print(message& message) override;

    consoleoutput() = default;
};


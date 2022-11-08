#pragma once
#include "logoutinfo.h"
#include "Message.h"
#include <vector>
#include "output.h"
#include "fileoutput.h"
#include "consoleoutput.h"
class logger
{
public:
    logger(logoutinfo* info);
    void print(message& msg);
private:
    std::vector<output*> outs;
};


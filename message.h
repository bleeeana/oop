#pragma once
#include <string>
#include <iostream>
#include "logoutinfo.h"
class message
{
public:
	explicit message(LEVEL type, std::string message, logoutinfo* info);
    LEVEL getType();
    std::string get_message();
    logoutinfo* get_info();
    std::string get_pref();
    friend std::ostream& operator<<(std::ostream& os, message& message);
private:
    LEVEL type;
    std::string msg;
    std::string pref;
    logoutinfo* info;
};


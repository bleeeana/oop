#include "pch.h"
#include "message.h"


message::message(LEVEL type, std::string message, logoutinfo* info)
{
    switch (type) {
    case GAME:
        this->pref = "[GAME]";
        break;
    case ERROR:
        this->pref = "[ERROR]";
        break;
    case STATUS:
        this->pref = "[STATUS]";
        break;
    }

    this->msg = message;
    this->type = type;
    this->info = info;
}

LEVEL message::getType()
{
	return type;
}

std::string message::get_message()
{
	return msg;
}

logoutinfo* message::get_info()
{
	return info;
}

std::string message::get_pref()
{
	return pref;
}

std::ostream& operator<<(std::ostream& os, message& message)
{
    os << message.get_pref() << ' ';
    os << message.get_message();
    os << std::endl;
    return os;
}

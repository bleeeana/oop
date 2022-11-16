#include "pch.h"
#include "logger.h"

logger::logger(logoutinfo* info)
{
    for (auto elem : info->get_outputs()) {
        switch (elem) {
        case FILEOUT:
            outs.push_back(new fileoutput("logs.txt"));
            break;
        case CONSOLE:
            outs.push_back(new consoleoutput);
            break;
        }
    }
}

void logger::print(message& msg)
{
	for (auto elem : outs)
		elem->print(msg);
}

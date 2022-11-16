#include "pch.h"
#include "fileoutput.h"

fileoutput::fileoutput(std::string name)
{
	file.open(name, std::ios_base::out | std::ios_base::app);
}

fileoutput::~fileoutput()
{
	file.close();
}

void fileoutput::print(message& message)
{
	if (file.is_open()) {
		file << message;
	}
}

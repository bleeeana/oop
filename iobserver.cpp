#include "pch.h"
#include "iobserver.h"

void iobserver::update(message& msg)
{
	logger logger(msg.get_info());
	logger.print(msg);
}

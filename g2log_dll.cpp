#include "g2log_dll.h"

#include "../src/g2log.h"
#include "../src/g2logworker.h"

#include <memory>
#include <iostream>

extern "C" int init_g2log (const char* prefix,const char* location) {

	g2::initializeLogging(new g2LogWorker(prefix, location));

	return 1;
}

extern "C" void stop_g2log () {
	g2::shutDownLogging();
}

extern "C" void printf_g2log(const char* _file,const int _line,const char* _function,const char* _level,const char* _message)
{
	g2::internal::LogMessage(_file,_line,_function,_level).messageSave("%s",_message);
}


#include "g2log_dll.h"

#include "../src/g2log.h"
#include "../src/g2logworker.h"

#include <memory>
#include <iostream>

static std::unique_ptr<g2LogWorker> current_worker=nullptr;

extern "C" __declspec(dllexport) int init_g2log (const char* prefix,const char* location) {

	current_worker.reset(new g2LogWorker(prefix, location));
	g2::initializeLogging(current_worker.get());

	return current_worker.get()!=nullptr?1:0;
}

extern "C" __declspec(dllexport) void stop_g2log () {
	g2::shutDownLogging();
	current_worker=0;
}

extern "C" __declspec(dllexport) void printf_g2log(const char* _file,const int _line,const char* _function,const char* _level,const char* _message)
{
	g2::internal::LogMessage(_file,_line,_function,_level).messageSave(_message);
}


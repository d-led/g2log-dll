#include "g2log_dll.h"

#include "../src/g2log.h"
#include "../src/g2logworker.h"

#include <memory>
#include <iostream>

static std::unique_ptr<g2LogWorker> current_worker=0;

extern "C" __declspec(dllexport) bool init_g2log (const char* prefix,const char* location) {

	current_worker.reset(new g2LogWorker(prefix, location));
	g2::initializeLogging(current_worker.get());

	std::cout<<current_worker.get()<<std::endl;
	return current_worker!=0;
}

extern "C" __declspec(dllexport) void stop_g2log () {
	g2::shutDownLogging();
	current_worker=0;
}


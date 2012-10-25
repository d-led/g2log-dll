#include <boost/timer/timer.hpp>

#include "../g2log_dll.h"

int main()
{
	boost::timer::auto_cpu_timer t;
	init_g2log("test",".");
	for (int i=0; i<1000000;i++) {
		printf_g2log("1",33,"2","WARN","a log message");
	}
	stop_g2log();
	return 0;
}
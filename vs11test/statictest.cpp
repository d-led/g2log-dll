#include <boost/timer/timer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>

#include <vector>
#include <string>

#include "../../src/g2log.h"
#include "../../src/g2logworker.h"

static void single_threaded_test(int count)
{
	boost::timer::auto_cpu_timer t;
	g2LogWorker worker("single",".");
	g2::initializeLogging(&worker);

	for (int i=0; i<count;i++) {
		g2::internal::LogMessage("1",33,"2","WARN").messageSave("%s","a log message");
	}
	g2::shutDownLogging();
}

class log_n_times
{
	std::string name;
	int times;
public:
	void operator()() const
	{
		for (int i=0; i<times;i++) {
			g2::internal::LogMessage("1",33,name.c_str(),"WARN").messageSave("%s","a log message");
		}
	}
public:
	log_n_times(int t,std::string const& n):times(t),name(n) {}
};

static void test_n_threads(int count,int thread_count)
{
	boost::timer::auto_cpu_timer t;
	std::string name=std::string("multi")+boost::lexical_cast<std::string>(thread_count);
	g2LogWorker worker(name.c_str(),".");
	g2::initializeLogging(&worker);

	boost::thread_group threads;

	//create threads
	for (int curr_thread=0; curr_thread<thread_count; curr_thread++) {
		std::string thread_name=name+"_"+boost::lexical_cast<std::string>(curr_thread);
		threads.add_thread(new boost::thread(log_n_times(count/thread_count,thread_name)));
	}

	//join
	threads.join_all();

	g2::shutDownLogging();
}

static void multi_threaded_test(int count,int max_threads)
{
	for (int thread_count=1; thread_count<=max_threads; thread_count++) {
		test_n_threads(count,thread_count);
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	}
}

int main()
{
	const int count=100000;
	single_threaded_test(count);
	multi_threaded_test(count,16);
	return 0;
}
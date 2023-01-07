#pragma once

#include <thread>
#include <atomic>
#include <functional>
#include <memory>
#include <stdexcept>
#include "HM_Logger.h"


class HM_Worker
{
private:
	std::thread m_thread;
	std::atomic_bool m_running;
	std::atomic_bool m_abort_requested;
	HM_Logger m_logger{LOG_LEVEL::LOG_LEVEL_INFO, "logs/HM_Worker.log"};
	

public:
	HM_Worker();
	~HM_Worker();
	bool run();
	void stop();
	bool is_running() const;

private:
	void run_func();
	void abort_and_join();
	
};

#pragma once

#include <thread>
#include <atomic>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <stdexcept>
#include "HM_Logger.h"

typedef std::function<void()> Runnable;

class HM_Worker
{
private:
	std::thread m_thread;
	std::atomic_bool m_running;
	std::atomic_bool m_abort_requested;
	HM_Logger m_logger{LOG_LEVEL::LOG_LEVEL_INFO, "logs/HM_Worker.log"};
	std::recursive_mutex m_runnable_mutex;
	std::queue<Runnable> m_runnable_queue;
	

public:
	HM_Worker();
	~HM_Worker();
	bool run();
	void stop();
	bool is_running() const;

private:
	void run_func();
	void abort_and_join();
	Runnable next();
	
};

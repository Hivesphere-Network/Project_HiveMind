#pragma once

#include <thread>
#include <atomic>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <stdexcept>
#include "HM_Logger.h"

class HM_Dispatcher;

typedef std::function<void()> Runnable;

class HM_Worker
{
	friend class HM_Dispatcher;
private:
	std::thread m_thread;
	std::atomic_bool m_running;
	std::atomic_bool m_abort_requested;
	HM_Logger m_logger{LOG_LEVEL::LOG_LEVEL_INFO, "logs/HM_Worker.log"};
	std::recursive_mutex m_runnable_mutex;
	std::queue<Runnable> m_runnable_queue;
	std::shared_ptr<HM_Dispatcher> m_dispatcher;
	

public:
	HM_Worker();
	~HM_Worker();
	bool run();
	void stop();
	bool is_running() const;
	std::shared_ptr<HM_Dispatcher> get_dispatcher();

private:
	void run_func();
	void abort_and_join();
	Runnable next();
	bool post(Runnable &&a_runnable);
	
};

class HM_Dispatcher
{
	friend class HM_Worker;
private:
	HM_Worker &m_worker;
	
public:
	bool post(Runnable &&runnable);
private:
	explicit HM_Dispatcher(HM_Worker &hm_worker) : m_worker(hm_worker) {}
};

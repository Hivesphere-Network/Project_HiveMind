#pragma once

#include <thread>
#include <atomic>
#include <functional>
#include <memory>
#include <stdexcept>

class HM_Worker
{
private:
	std::thread m_thread;
	std::atomic_bool m_running;
	std::atomic_bool m_abort_requested;

public:
	HM_Worker(const HM_Worker&);
	~HM_Worker();
	bool run();
	void stop();
	bool is_running() const;

private:
	void run_func();
	void abort_and_join();
	
};

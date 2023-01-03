#pragma once

#include <thread>
#include <atomic>
#include <functional>
#include <memory>
#include <stdexcept>

class Worker
{
private:
	std::thread m_thread;
	std::atomic_bool m_running;
	std::atomic_bool m_abort_requested;

public:
	Worker(const Worker&);
	~Worker();
	bool run();
	bool stop();
	bool is_running();

private:
	bool run_func();
	bool abort_and_join();
	
};

#include "Worker.h"

Worker::Worker(const Worker&)
{
	
}

Worker::~Worker()
{
	this->abort_and_join();
}

bool Worker::run()
{
	try
	{
		m_thread = std::thread(&Worker::run_func, this);
	}
	catch(...)
	{
		return false;
	}
	return true;
}

void Worker::stop()
{
	this->abort_and_join();
}

bool Worker::is_running() const
{
	return m_running.load();
}	

void Worker::run_func()
{
	m_running.store(true);

	while(m_abort_requested.load() == false)
	{
		try
		{
			
		}
		catch(std::runtime_error& error)
		{
			
		}
		catch(...)
		{
			
		}
	}
	m_running.store(false);
}

void Worker::abort_and_join()
{
	m_abort_requested.store(true);
	if(m_thread.joinable())
	{
		m_thread.join();
	}
}
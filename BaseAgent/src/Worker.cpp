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
	m_running.store(true);
	
	while(m_abort_requested.load() == false)
	{
		try
		{
			m_thread = std::thread(&Worker::run_func, this);
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

bool Worker::stop()
{
	this->abort_and_join();
}

bool Worker::is_running()
{
	
}

bool Worker::run_func()
{
	
}

bool Worker::abort_and_join()
{
	m_abort_requested.store(true);
	if(m_thread.joinable())
	{
		m_thread.join();
	}
}
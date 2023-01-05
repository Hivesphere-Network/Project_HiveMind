#include "HM_Worker.h"

HM_Worker::HM_Worker(const HM_Worker&)
{
	
}

HM_Worker::~HM_Worker()
{
	this->abort_and_join();
}

bool HM_Worker::run()
{
	try
	{
		m_thread = std::thread(&HM_Worker::run_func, this);
	}
	catch(...)
	{
		return false;
	}
	return true;
}

void HM_Worker::stop()
{
	this->abort_and_join();
}

bool HM_Worker::is_running() const
{
	return m_running.load();
}	

void HM_Worker::run_func()
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

void HM_Worker::abort_and_join()
{
	m_abort_requested.store(true);
	if(m_thread.joinable())
	{
		m_thread.join();
	}
}
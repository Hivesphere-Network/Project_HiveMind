#include "HM_Worker.h"

HM_Worker::HM_Worker()
{
	m_logger.info("HM_Worker starting");
}

HM_Worker::~HM_Worker()
{
	m_logger.info("HM_Worker stopping");
	this->abort_and_join();
}

bool HM_Worker::run()
{
	try
	{
		m_logger.info("HM_Worker Thread running");
		m_thread = std::thread(&HM_Worker::run_func, this);
	}
	catch(...)
	{
		m_logger.error("Failed to start HM_Worker thread");
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
			m_logger.info("HM_Worker running");
			throw std::runtime_error("test");
		}
		catch(std::runtime_error& error)
		{
			m_logger.error(("HM_Worker::run_func() - %s", error.what()));
		}
		catch(...)
		{
			m_logger.error("HM_Worker::run_func() - unknown error");
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
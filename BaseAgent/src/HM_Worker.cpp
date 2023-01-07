#include "HM_Worker.h"


HM_Worker::HM_Worker() : m_dispatcher(std::shared_ptr<HM_Dispatcher>(new HM_Dispatcher(*this)))
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

std::shared_ptr<HM_Dispatcher> HM_Worker::get_dispatcher()
{
	return m_dispatcher;
}

void HM_Worker::run_func()
{
	m_running.store(true);

	while(m_abort_requested.load() == false)
	{
		try
		{
			if(Runnable current_runnable = next()) current_runnable();
			else
			{
				m_logger.warn("HM_Worker Thread has no work to do. Sleeping for 10 milliseconds");
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
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

Runnable HM_Worker::next()
{
	std::lock_guard guard(m_runnable_mutex);
	if(m_runnable_queue.empty())
	{
		return nullptr;
	}
	Runnable runnable = m_runnable_queue.front();
	m_runnable_queue.pop();

	return runnable;
}

bool HM_Worker::post(Runnable&& a_runnable)
{
	if(!m_running.load())
	{
		m_logger.error("HM_Worker::post() - worker is not running");
		return false;
	}
	try
	{
		std::lock_guard guard(m_runnable_mutex);
		m_runnable_queue.push(std::move(a_runnable));
		m_logger.info("HM_Worker::post() - posted runnable");
		return true;
	}
	catch(...)
	{
		m_logger.error("HM_Worker::post() - failed to post runnable");
		return false;
	}
}

bool HM_Dispatcher::post(Runnable &&runnable)
{
	return m_worker.post(std::move(runnable));
}



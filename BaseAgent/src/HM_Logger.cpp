#include "HM_Logger.h"
#include <ctime>
#include <iostream>

HM_Logger::HM_Logger()
{
	m_log_file = "logs/base_log.log";
	m_file = new HM_File(m_log_file.c_str(), std::ios::in | std::ios::out | std::ios::app);
	m_log_level = LOG_LEVEL::LOG_LEVEL_INFO;
}

HM_Logger::HM_Logger(const LOG_LEVEL log_level,const std::string& log_file)
{
	m_log_file = log_file;
	m_file = new HM_File(m_log_file.c_str(), std::ios::in | std::ios::out | std::ios::app);
	m_log_level = log_level;
}

HM_Logger::~HM_Logger()
{
	write_log();
	delete m_file;
}

void HM_Logger::info(const std::string& log_string)
{
	const std::string log = "[" + get_time() + "] [INFO]  " + log_string + "\n";
	m_log_queue.append(log);
}

void HM_Logger::warn(const std::string& log_string)
{
	const std::string log = "[" + get_time() + "] [WARN]  " + log_string + "\n";
	m_log_queue.append(log);
}

void HM_Logger::error(const std::string& log_string)
{
	const std::string log = "[" + get_time() + "] [ERROR] " + log_string + "\n";
	m_log_queue.append(log);
}

void HM_Logger::debug(const std::string& log_string)
{
	const std::string log = "[" + get_time() + "] [DEBUG] " + log_string + "\n";
	m_log_queue.append(log);
}

void HM_Logger::write_log() const
{
	m_file->append(m_log_queue);
}

std::string HM_Logger::get_time()
{
	time_t raw_time;
	char buffer[80];

	time(&raw_time);
	const tm* time_info = localtime(&raw_time);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
	std::string str(buffer);

	return str;
}


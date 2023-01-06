#include "HM_Logger.h"
#include <ctime>

HM_Logger::HM_Logger()
{
	m_log_file = "logs/base_log.txt";
	m_file = new HM_File(m_log_file.c_str(), std::ios::in | std::ios::out | std::ios::app);
	m_log_level = LOG_LEVEL::LOG_LEVEL_INFO;
}

HM_Logger::~HM_Logger()
{
	write_log();
	delete m_file;
}

void HM_Logger::info(const std::string& log_string)
{
	const std::string log = "[" + get_time() + "][INFO]" + log_string;
	m_log_queue.append(log);
}

void HM_Logger::debug(const std::string& log_string)
{
	const std::string log = "[" + get_time() + "][DEBUG]" + log_string;
	m_log_queue.append(log);
}

void HM_Logger::write_log() const
{
	m_file->append(m_log_queue);
}

std::string HM_Logger::get_time()
{
	time_t raw_time;
	struct tm* time_info;
	char buffer[80];

	time(&raw_time);
	time_info = localtime(&raw_time);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", time_info);
	std::string str(buffer);

	return str;
}


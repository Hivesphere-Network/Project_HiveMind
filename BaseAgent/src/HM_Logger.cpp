#include "HM_Logger.h"

HM_Logger::HM_Logger()
{
	m_log_file = "logs/base_log.txt";
	m_file = new HM_File(m_log_file.c_str(), std::ios::in | std::ios::out | std::ios::app);
	m_log_level = LOG_LEVEL::LOG_LEVEL_INFO;
}

HM_Logger::~HM_Logger()
{
	delete m_file;
}

void HM_Logger::info(const std::string& log_string)
{
	m_log_queue.append("[INFO] " + log_string + "\n");
}

void HM_Logger::debug(const std::string& log_string)
{
	m_log_queue.append("[DEBUG] " + log_string + "\n");
}

void HM_Logger::write_log() const
{
	m_file->append(m_log_queue);
}


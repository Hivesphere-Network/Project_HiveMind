#pragma once

#include <ctime>
#include <string>

#include "HM_File.h"

enum class LOG_LEVEL
{
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_ERROR
};

class HM_Logger
{
private:
	HM_File* m_file;
	LOG_LEVEL m_log_level;
	std::string m_log_file;

	std::string m_log_queue;
	
public:
	HM_Logger();
	HM_Logger(LOG_LEVEL log_level, const std::string& log_file);
	~HM_Logger();

	void info(const std::string& log_string);
	void debug(const std::string& log_string);
	void warn(const std::string& log_string);
	void error(const std::string& log_string);

private:
	void write_log() const;
	static std::string get_time();
};


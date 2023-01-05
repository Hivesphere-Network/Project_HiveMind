#pragma once
#include <fstream>

class HM_File
{
private:
	std::fstream m_file;

public:
	HM_File(const char* path, const int mode);
	~HM_File();
	void append(const std::string& str);
	std::string read();
	void write(const std::string& context);

private:
	void close();
};

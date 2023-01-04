#pragma once
#include <fstream>

class HM_File
{
private:
	std::fstream m_file;
public:
	HM_File(const char* path, const int mode);
	bool close();
	void append();
	void read();
	void write();
};

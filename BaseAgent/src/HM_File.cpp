#include "HM_File.h"
#include <cstdio>

HM_File::HM_File(const char* path, const int mode)
{
	m_file.open(path, mode);
}

void HM_File::append(std::string str)
{
	m_file << str;
}



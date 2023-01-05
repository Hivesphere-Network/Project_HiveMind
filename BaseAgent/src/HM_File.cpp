#include "HM_File.h"

#include <iostream>
#include <string>


HM_File::HM_File(const char* path, const int mode)
{
	m_file.open(path, mode);
}

HM_File::~HM_File()
{
	this->close();
}

void HM_File::append(const std::string& str)
{
	m_file << str;
}

std::string HM_File::read()
{
	std::string context;
	std::string line;
	while (std::getline(m_file, line))
	{
		context.append("\n");
		context.append(line);
	}
	return context;
}

void HM_File::write(const std::string& context)
{
	m_file << context;
}


void HM_File::close()
{
m_file.close();
}



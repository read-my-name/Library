#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <cerrno>

class CIniParser
{
public:
	CIniParser();
	~CIniParser();

	std::uintmax_t getFileSize(std::string strFileName);
	std::string strGetValue(const std::string strFilePath, const std::string& section, const std::string& key, const std::string strDefault = "", bool isAppend = false);
	
private:
	std::string strGet(const std::string strFilePath, const std::string& section, const std::string& key, const std::string strDefault = "");
	std::string strGetAndSet(const std::string strFilePath, const std::string& section, const std::string& key, const std::string strDefault);

};


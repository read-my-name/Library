#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <direct.h>


class CLogger
{
public:
	CLogger(std::string strPath);
	~CLogger();

public:
	// Set the type to your preference such as "Alert", "Debug", "ClassName" and etc
	bool bLogToFile(std::string strType, std::string strMsg);
	/*
	Change the mode
	1: Number of entries (Default)
	2: Size of the file
	3: Time interval (Under development)
	*/
	void vSetMode(int iMode);
	// Change this according to your preference
	void vSetMaxEntry(int iEntry = 100);
	void vSetMaxFileSize(int iByte = 5);
	
private:
	static std::string m_strPath;
	static std::string m_strFile;
	static int m_iMode;
	static int m_iNumOfEntry;

	
	static int m_iMaxEntry;
	static int m_iMaxSize;
	//static std::chrono::steady_clock::time_point m_startTime;
	//static bool m_bInitialized;

private:
	std::string sGetTimeString(int iFormat);
	//std::string sParseMilliSecond(long long llMicrosecondsCount);
	bool bCreateDirectory(const std::string& strPath);
	long double ldGetFileSize(std::string strFileName);
	//double dGetTimeInterval();
};

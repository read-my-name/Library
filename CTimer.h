#pragma once
#include "include.h"

class CTimer
{
	//https://www.programiz.com/cpp-programming/library-function/ctime/strftime
public:
	CTimer();
	~CTimer();

private:
	enum eTimeFormat
	{
		eSTRING_TIME,
		eSTRING_YEAR,
		eSTRING_MONTH,
		eSTRING_DAY,
		eSTRING_HOURS,
		eSTRING_MINS,
		eSTRING_SECOND,
		eSTRING_DAYOFWEEK,

		eSTRING_DEFAULT = -1
	};

public:
	std::string getCurrentStdTime();
	std::string getCurrentTime();
	std::string getCurrentYear();
	std::string getCurrentMonth();
	std::string getCurrentDay();
	std::string getCurrentHours();
	std::string getCurrentMinutes();
	std::string getCurrentSeconds();
	std::string getCurrentDayOfWeek();

private:
	std::string getTime(eTimeFormat eFormat = eSTRING_DEFAULT);
};


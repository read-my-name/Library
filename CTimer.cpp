#include "CTimer.h"

CTimer::CTimer()
{

}

CTimer::~CTimer()
{

}

std::string CTimer::getTime(eTimeFormat eFormat /* = 0 */)
{
    time_t      now = time(0);
    struct tm   tstruct;
    char        buf[80];
    std::string sRes;

    localtime_s(&tstruct, &now);
    //strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    switch (eFormat)
    {
        case eSTRING_TIME:
            strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
            break;
        case eSTRING_YEAR:
            strftime(buf, sizeof(buf), "%Y", &tstruct);
            break;
        case eSTRING_MONTH:
            strftime(buf, sizeof(buf), "%m", &tstruct);
            break;
        case eSTRING_DAY:
            strftime(buf, sizeof(buf), "%d", &tstruct);
            break;
        case eSTRING_HOURS:
            strftime(buf, sizeof(buf), "%H", &tstruct);
            break;
        case eSTRING_MINS:
            strftime(buf, sizeof(buf), "%M", &tstruct);
            break;
        case eSTRING_SECOND:
            strftime(buf, sizeof(buf), "%S", &tstruct);
            break;
        case eSTRING_DAYOFWEEK:
            strftime(buf, sizeof(buf), "%aday", &tstruct);
            break;
        case eSTRING_DEFAULT:
        default:
            strftime(buf, sizeof(buf), "%c", &tstruct);
            break;
    }
    //std::string sRes(buf);
    sRes.assign(buf);
	return sRes;
}

std::string CTimer::getCurrentStdTime()
{
    std::string sRes("");
    sRes = getTime(eSTRING_DEFAULT);
    return sRes;
}

std::string CTimer::getCurrentTime()
{
    std::string sRes("");
    sRes = getTime(eSTRING_TIME);
    return sRes;
}

std::string CTimer::getCurrentYear()
{
    std::string sRes("");
    sRes = getTime(eSTRING_YEAR);
    return sRes;
}

std::string CTimer::getCurrentMonth()
{
    std::string sRes("");
    sRes = getTime(eSTRING_MONTH);
    return sRes;
}

std::string CTimer::getCurrentDay()
{
    std::string sRes("");
    sRes = getTime(eSTRING_DAY);
    return sRes;
}

std::string CTimer::getCurrentHours()
{
    std::string sRes("");
    sRes = getTime(eSTRING_HOURS);
    return sRes;
}

std::string CTimer::getCurrentMinutes()
{
    std::string sRes("");
    sRes = getTime(eSTRING_MINS);
    return sRes;
}

std::string CTimer::getCurrentSeconds()
{
    std::string sRes("");
    sRes = getTime(eSTRING_SECOND);
    return sRes;
}

std::string CTimer::getCurrentDayOfWeek()
{
    std::string sRes("");
    sRes = getTime(eSTRING_DAYOFWEEK);
    return sRes;
}
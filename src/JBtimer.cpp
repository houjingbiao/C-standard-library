#include "JBtimer.h"
#include <time.h>
#if __linux
#include <sys/time.h>
#else
#include <windows.h>
#endif

my_time_t gettime_second()
{
	time_t tt;
	time(&tt);
	return (my_time_t)tt;
}



my_time_t gettime_millisecond()
{
#if __linux
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#else

	// 获取微秒级别的系统时间
	SYSTEMTIME tval;
	GetLocalTime(&tval);

	//printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", tval.wYear, tval.wMonth, tval.wDay, tval.wHour, tval.wMinute, tval.wSecond, tval.wMilliseconds, tval.wDayOfWeek);

	// 构造秒级的时间结构
	struct tm tval_sec;
	tval_sec.tm_sec = tval.wSecond;
	tval_sec.tm_min = tval.wMinute;
	tval_sec.tm_hour = tval.wHour;
	tval_sec.tm_mday = tval.wDay;
	tval_sec.tm_mon = tval.wMonth - 1;
	tval_sec.tm_year = tval.wYear - 1900;

	// 转换获得微秒级别时间
	my_time_t abc = (my_time_t)mktime(&tval_sec) * 1000 + tval.wMilliseconds;
	return abc;
#endif
}

my_time_t gettime_microsecond()
{
#if __linux
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
#else
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	double dqfreq = f.QuadPart;

	LARGE_INTEGER tt;
	QueryPerformanceCounter(&tt);

	return tt.QuadPart / dqfreq * 1000000;
#endif
}


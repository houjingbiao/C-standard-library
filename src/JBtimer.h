#ifndef __JB_TIME_H__
#define __JB_TIME_H__

#include <stdio.h>
#if __linux
#include <sys/time.h>
#else
#include <windows.h>
#endif

typedef long long my_time_t;

#if __linux
my_time_t gettime_millisecond()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
#else
my_time_t gettime_millisecond()
{
	// ��ȡ΢�뼶���ϵͳʱ��
	SYSTEMTIME tval;
	GetLocalTime(&tval);

	//printf("%4d/%02d/%02d %02d:%02d:%02d.%03d ����%1d\n", tval.wYear, tval.wMonth, tval.wDay, tval.wHour, tval.wMinute, tval.wSecond, tval.wMilliseconds, tval.wDayOfWeek);

	// �����뼶��ʱ��ṹ
	struct tm tval_sec;
	tval_sec.tm_sec = tval.wSecond;
	tval_sec.tm_min = tval.wMinute;
	tval_sec.tm_hour = tval.wHour;
	tval_sec.tm_mday = tval.wDay;
	tval_sec.tm_mon = tval.wMonth - 1;
	tval_sec.tm_year = tval.wYear - 1900;

	// ת�����΢�뼶��ʱ��
	my_time_t abc = (my_time_t)mktime(&tval_sec) * 1000 + tval.wMilliseconds;
	return abc;
}
#endif

#endif//__JB_TIME_H__
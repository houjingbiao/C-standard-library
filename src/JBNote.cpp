time_t;// 时间算术类型

struct tm//时间组成类型
{
	int tm_sec;   // seconds after the minute - [0, 60] including leap second
	int tm_min;   // minutes after the hour - [0, 59]
	int tm_hour;  // hours since midnight - [0, 23]
	int tm_mday;  // day of the month - [1, 31]
	int tm_mon;   // months since January - [0, 11]
	int tm_year;  // years since 1900
	int tm_wday;  // days since Sunday - [0, 6]
	int tm_yday;  // days since January 1 - [0, 365]
	int tm_isdst; // daylight savings time flag
};

//描述：
//说明
//参数：
//返回：

//cpu使用的时间
//返回：程序使用的处理器时钟数，不能获取的时候返回(clock_t)-1
clock_t clock(void);
//描述：时间差
//参数：
//返回：类型为double
double difftime(time_t time1, time_t time0);
//描述：实现两种时间类型之间的转换
//参数：
//返回：
time_t mktime(struct tm *timeptr);
//描述：获取当前时间
//参数：如果参数值不为空，则返回值赋值给它指向的对象
//返回：
time_t time(time_t *timer);
//描述：将时间组成类型转换为字符串"Sun Sep 16 01:03:52 1973\n\0"，其中asc为ascii的意思，就是字符串的代名词
//参数：
//返回：字符串
char * asctime(const struct tm *timeptr);
//描述：将时间算术类型转换为字符串，等价于asctime(ctime(const time_t* timer))
//参数：
//返回：
char * ctime(const time_t *timer);
//描述：将timer指向的时间转换成UTC（Coordinated Universal Timer）表示的时间组成类型
//参数：
//返回：若UTC不可用，返回NULL
struct tm *gmtime(const time_t *timer);
//描述：将timer指向的时间转换成本地时间表示的时间组成类型
//参数：timer不能为NULL
//返回：
struct tm *localtime(const time_t *timer);
//注意：上面四个返回值为指针类型的函数，指针都指向一个共享的静态对象（时间组成类型或者是char数组），多次执行会发生覆盖
//描述：时间格式化输出，具体的输出会因为区域设置LC_TIME的不同而产生很大变化
//参数：format定义了专门的时间输出格式，模仿printf输出，但是是strftime专用的一套
//返回：如果包括终止符在内字符数小于等于maxsize则返回该数字，否则返回0
size_t strftime(char *s, size_t maxsize, const char *format, const struct tm *timeptr);


文件读写
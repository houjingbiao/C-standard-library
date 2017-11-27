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



#include <stdio.h>
//类型
size_t
FILE //对象类型，记录控制流所需要的所有信息
fpos_t //对象类型，唯一指定文件中的每一个位置所需要的信息
//宏
NULL
_IOFBF //作为setvbuf的参数使用
_IOLBF //作为setvbuf的参数使用
_IONBF //作为setvbuf的参数使用
BUFSIZ //展开为一个整值常量表达式，指的是setbuf函数使用的缓冲大小
EOF //流结束
FOPEN_MAX //最多同时打开的文件数
FILENAME_MAX //文件名长度
L_tmpnam //这个宏是一个整数，该整数代表了字符数组可以存储的由 tmpnam 函数创建的临时文件名的最大长度。
SEEK_CUR //fseek函数的第三个参数
SEEK_END//fseek函数的第三个参数
SEEK_SET//fseek函数的第三个参数
TMP_MAX //这个宏是 tmpnam 函数可生成的独特文件名的最大数量。
stderr //标准错误、标准输入和标准输出流。
stdin
stdout


//文件操作
//描述：删除文件
//参数：
//返回：成功0，否则-1并设置errno
int remove(const char *filename);
//描述：修改文件名
//参数：
//返回：成功返回0，否则-1并置errno
int rename(const char *old, const char *new);
//描述：创建临时文件，在流关闭或者程序终止的时候，文件自动删除
//参数：
//返回：成功返回流指针，否则NULL
FILE *tmpfile(void);
//描述：生成并返回一个有效的临时文件名，
//参数：s是指向字符数组的指针，其中临时文件名被存储为C字符串
//返回：一个指向C字符串的指针，该字符串存储了临时文件名。s=NULL时，该指针指向一个内部缓冲区，下次调用该缓冲区会被覆盖，
//str!=NULL，则返回str。如果函数未能创建成功，则返回NULL
char *tmpnam(char *s);

//文件访问
//描述：关闭文件流
//参数：
//返回：成功返回0，否则返回EOF
int fclose(FILE *stream);
//描述：刷新流的输出缓冲区
//参数：
//返回：成功0，否则EOF，且置feof
int fflush(FILE *stream);
//描述：打开文件
//参数：r（只读，文件必须存在），w（写入，如果存在，则清空原文件），a（追加），r+（可读可写，文件必须存在），
//w+（创建一个用于读写的空文件），a+（打开一个用于读取和追加的文件）
//返回：成功FILE指针，否则NULL，且置errno
//mode 有下列几种形态字符串 :
//r 以只读方式打开文件，该文件必须存在。
//r + 以可读写方式打开文件，该文件必须存在。
//rb + 读写打开一个二进制文件，允许读数据。
//rw + 读写打开一个文本文件，允许读和写。
//w 打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件。
//w + 打开可读写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。
//a 以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。（EOF符保留）
//a + 以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 （原来的EOF符不保留）
//wb 只写打开或新建一个二进制文件；只允许写数据。
//wb + 读写打开或建立一个二进制文件，允许读和写。
//ab + 读写打开一个二进制文件，允许读或在文件末追加数据。
//at + 打开一个叫string的文件，a表示append, 就是说写入处理的时候是接着原来文件已有内容写入，不是从头写入覆盖掉，t表示打开文件的类型是文本文件， + 号表示对文件既可以读也可以写。
//上述的形态字符串都可以再加一个b字符，如rb、w + b或ab + 等组合，加入b 字符用来告诉函数库以二进制模式打开文件。如果不加b，表示默认加了t，即rt, wt, 其中t表示以文本模式打开文件。由fopen()所建立的新文件会具有S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH(0666)权限，此文件权限也会参考umask 值。
//有些C编译系统可能不完全提供所有这些功能，有的C版本不用"r+", "w+", "a+", 而用"rw", "wr", "ar"等，读者注意所用系统的规定。
//二进制和文本模式的区别
//1.在windows系统中，文本模式下，文件以"\r\n"代表换行。若以文本模式打开文件，并用fputs等函数写入换行符"\n"时，函数会自动在"\n"前面加上"\r"。即实际写入文件的是"\r\n" 。
//2.在类Unix / Linux系统中文本模式下，文件以"\n"代表换行。所以Linux系统中在文本模式和二进制模式下并无区别。
FILE* fopen(const char *filename, const char *mode);
//描述：
//参数：
//返回：
FILE* freopen(const char *filename, const char *mode, FILE *stream);
//描述：
//参数：
//返回：
void setbuf(FILE *stream, char *buf);
//描述：
//参数：
//返回：
int setvbuf(FILE *stream, char *buf, int mode, size_t size);

//格式化输出
//描述：
//参数：
//返回：
int fprintf(FILE *stream, const char *format, ... );
//描述：
//参数：
//返回：
int fscanf(FILE *stream, const char *format, ... );

//描述：
//参数：
//返回：
int printf(const char *format, ...);

//描述：
//参数：
//返回：
int scanf(const char *format, ...);

//描述：
//参数：
//返回：
int sprintf(char *s, const char* format, ...);

//描述：
//参数：
//返回：
int sscanf(const char *s, const char* format, ...);

//描述：
//参数：
//返回：
int vfprintf(FILE *stream, const char *format, va_list arg);

//描述：
//参数：
//返回：
int vprintf(const char *format, va_list arg);

//描述：
//参数：
//返回：
int vsprintf(char *s, const char *format, va_list arg);


//字符输入输出函数
//描述：
//参数：
//返回：
int fgetc(FILE *stream);

//描述：
//参数：
//返回：
char *fgets(char *s, int n, FILE *stream);

//描述：
//参数：
//返回：
int fputc(int c, FILE *stream);

//描述：
//参数：
//返回：
int fputs(const char *s, FILE *stream);

//描述：
//参数：
//返回：
int getc(FILE *stream);

//描述：
//参数：
//返回：
int getchar(void);

//描述：
//参数：
//返回：
char *gets(char *s);

//描述：
//参数：
//返回：
int putc(int c, FILE *stream);

//描述：
//参数：
//返回：
int putchar(int c);

//描述：
//参数：
//返回：
int puts(const char *s);

//描述：
//参数：
//返回：
int ungetc(int c, FILE *stream);

//描述：
//参数：
//返回：
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

//描述：
//参数：
//返回：
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);


//文件定位函数
//描述：
//参数：
//返回：
int fgetpos(FILE *stream, fpos_t *pos);

//描述：
//参数：
//返回：
int fseek(FILE *stream, long int offset, int whence);

//描述：
//参数：
//返回：
int fsetpos(FILE *stream, fpos_t *pos);

//描述：
//参数：
//返回：
long int ftell(FILE *stream);

//描述：
//参数：
//返回：
void rewind(FILE *stream);

//错误处理函数

//描述：
//参数：
//返回：
void clearerr(FILE *stream);

//描述：
//参数：
//返回：
int feof(FILE *stream);

//描述：
//参数：
//返回：
int ferror(FILE *stream);

//描述：
//参数：
//返回：
void perror(const char *s);
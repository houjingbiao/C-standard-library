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
BUFSIZ //展开为一个整值常量表达式，指的是setbuf函数使用的缓冲的最小值
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
//描述：把一个新的文件名 filename 与给定的打开的流 stream 关联，同时关闭流中的旧文件。
//参数：参数stream执行FILE对象，标识了要被重新打开的流
//返回：成功返回一个只想标识流的指针，否则NULL
FILE* freopen(const char *filename, const char *mode, FILE *stream);
//描述：定义流 stream 应如何缓冲。该函数应在与流 stream 相关的文件被打开时，且还未发生任何输入或输出操作之前被调用一次。
//参数：将buf缓冲分配给stream使用，buf长度至少为BUFSIZ
//返回：
void setbuf(FILE *stream, char *buf);
//描述：定义流 stream 应如何缓冲。
//参数：stream同上，buf缓冲为NULL时，该函数自动分配一个指定大小的缓冲，
//mode缓冲模式，
//_IOFBF全缓冲：对于输出，数据在缓冲填满时被一次性写入。对于输入，缓冲会在请求输入且缓冲为空时被填充。
//_IOLBF行缓冲：对于输出，数据在遇到换行符或者在缓冲填满时被写入，具体视情况而定。对于输入，缓冲会在请求输入且缓冲为空时被填充，直到遇到下一个换行符。
//_IONBF	无缓冲：不使用缓冲。每个 I / O 操作都被即时写入。buffer 和 size 参数被忽略。
//size --这是缓冲的大小，以字节为单位。
//返回：如果成功，则该函数返回 0，否则返回非零值。
int setvbuf(FILE *stream, char *buf, int mode, size_t size);

//格式化输出
//描述：
//参数：
//返回：
int fprintf(FILE *stream, const char *format, ... );

//描述：格式化流输出
//参数：format的标签属性是： %[flags][width][.precision][length]specifier
//返回：
int fscanf(FILE *stream, const char *format, ... );

//描述：格式化流输入
//flags
//d, i	以十进制形式输出带符号整数(正数不输出符号)
//o	以八进制形式输出无符号整数(不输出前缀0)
//x, X	以十六进制形式输出无符号整数(不输出前缀Ox)
//u	以十进制形式输出无符号整数
//*//f	以小数形式输出单、双精度实数
//*//e, E	以指数形式输出单、双精度实数
//*//g, G	以%f或%e中较短的输出宽度输出单、双精度实数
//c	输出单个字符
//s	输出字符串
//p	输出指针地址
//*//lu	32位无符号整数
//*//llu	64位无符号整数

//width
//*//(number)要输出的字符的最小数目。如果输出的值短于该数，结果会用空格填充。如果输出的值长于该数，结果不会被截断。
//*// *	宽度在 format 字符串中未指定，但是会作为附加整数值参数放置于要被格式化的参数之前。

//.precision
//*//.number	对于整数说明符（d、i、o、u、x、X）：precision 指定了要写入的数字的最小位数。如果写入的值短于该数，结果会用前导零来填充。如果写入的值长于该数，结果不会被截断。精度为 0 意味着不写入任何字符。
//对于 e、E 和 f 说明符：要在小数点后输出的小数位数。
//对于 g 和 G 说明符：要输出的最大有效位数。
//对于 s : 要输出的最大字符数。默认情况下，所有字符都会被输出，直到遇到末尾的空字符。
//对于 c 类型：没有任何影响。
//当未指定任何精度时，默认为 1。如果指定时不带有一个显式值，则假定为 0。
//*// .*精度在 format 字符串中未指定，但是会作为附加整数值参数放置于要被格式化的参数之前。

//length
//*// h	参数被解释为短整型或无符号短整型（仅适用于整数说明符：i、d、o、u、x 和 X）。
//*// l	参数被解释为长整型或无符号长整型，适用于整数说明符（i、d、o、u、x 和 X）及说明符 c（表示一个宽字符）和 s（表示宽字符字符串）。
//*// L	参数被解释为长双精度型（仅适用于浮点数说明符：e、E、f、g 和 G）。

//参数：
//返回：
int printf(const char *format, ...);

//描述：
//参数：format: [=%[*][width][modifiers]type=]
//*	这是一个可选的星号，表示数据是从流 stream 中读取的，但是可以被忽视，即它不存储在对应的参数中。
//width	这指定了在当前读取操作中读取的最大字符数。
//modifiers	为对应的附加参数所指向的数据指定一个不同于整型（针对 d、i 和 n）、无符号整型（针对 o、u 和 x）或浮点型（针对 e、f 和 g）的大小： h ：短整型（针对 d、i 和 n），或无符号短整型（针对 o、u 和 x） l ：长整型（针对 d、i 和 n），或无符号长整型（针对 o、u 和 x），或双精度型（针对 e、f 和 g） L ：长双精度型（针对 e、f 和 g）
//type	一个字符，指定了要被读取的数据类型以及数据读取方式。具体参见下一个表格。

//c	单个字符：读取下一个字符。如果指定了一个不为 1 的宽度 width，函数会读取 width 个字符，并通过参数传递，把它们存储在数组中连续位置。在末尾不会追加空字符。对应的参数类型为char *
//d	十进制整数：数字前面的 + 或 - 号是可选的。对应的参数类型为int *
//e, E, f, g, G	浮点数：包含了一个小数点、一个可选的前置符号 + 或 - 、一个可选的后置字符 e 或 E，以及一个十进制数字。两个有效的实例 - 732.103 和 7.12e4	对应的参数类型为float *
//o	八进制整数。对应的参数类型为int *
//s	字符串。这将读取连续字符，直到遇到一个空格字符（空格字符可以是空白、换行和制表符）。对应的参数类型为char *
//u	无符号的十进制整数。对应的参数类型为unsigned int *
//x, X	十六进制整数。对应的参数类型为int *
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
//描述：从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。
//参数：
//返回：以无符号 char 强制转换为 int 的形式返回读取的字符，如果到达文件末尾或发生读错误，则返回 EOF。
int fgetc(FILE *stream);

//描述：从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。
//参数：
//返回：如果成功，该函数返回相同的 str 参数。如果到达文件末尾或者没有读取到任何字符，str 的内容保持不变，并返回一个空指针。如果发生错误，返回一个空指针。
char *fgets(char *s, int n, FILE *stream);

//描述：把参数 char 指定的字符（一个无符号字符）写入到指定的流 stream 中，并把位置标识符往前移动。
//参数：
//返回：如果没有发生错误，则返回被写入的字符。如果发生错误，则返回 EOF，并设置错误标识符。
int fputc(int c, FILE *stream);

//描述：把字符串写入到指定的流 stream 中，但不包括空字符。
//参数：
//返回：该函数返回一个非负值，如果发生错误则返回 EOF
int fputs(const char *s, FILE *stream);

//描述：从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。
//参数：
//返回：
int getc(FILE *stream);

//描述：从标准输入 stdin 获取一个字符（一个无符号字符）。这等同于 getc 带有 stdin 作为参数。
//参数：
//返回：
int getchar(void);

//描述：从标准输入 stdin 读取一行，并把它存储在 str 所指向的字符串中。当读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。
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

//描述：把一个字符串写入到标准输出 stdout，直到空字符，但不包括空字符。换行符会被追加到输出中。
//参数：
//返回：
int puts(const char *s);

//描述：把字符 char（一个无符号字符）推入到指定的流 stream 中，以便它是下一个被读取到的字符。
//参数：
//返回：
int ungetc(int c, FILE *stream);

//描述：从给定流 stream 读取数据到 ptr 所指向的数组中。
//参数：size这是要读取的每个元素的大小，以字节为单位。
//nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
//返回：成功读取的元素总数会以 size_t 对象返回，size_t 对象是一个整型数据类型。如果总数与 nmemb 参数不同，则可能发生了一个错误或者到达了文件末尾。
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

//描述：
//参数：
//返回：如果成功，该函数返回一个 size_t 对象，表示元素的总数，该对象是一个整型数据类型。如果该数字与 nmemb 参数不同，则会显示一个错误
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);


//文件定位函数
//描述：获取流 stream 的当前文件位置，并把它写入到 pos。
//参数：
//返回：如果成功，该函数返回零。如果发生错误，则返回非零值。
int fgetpos(FILE *stream, fpos_t *pos);

//描述：设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。
//参数：offset -- 这是相对 whence 的偏移量，以字节为单位。
//whence -- 这是表示开始添加偏移 offset 的位置。它一般指定为下列常量之一：
//SEEK_SET	文件的开头
//SEEK_CUR	文件指针的当前位置
//SEEK_END	文件的末尾
//返回：如果成功，则该函数返回零，否则返回非零值。
int fseek(FILE *stream, long int offset, int whence);

//描述：设置给定流 stream 的文件位置为给定的位置。参数 pos 是由函数 fgetpos 给定的位置。
//参数：
//返回：如果成功，该函数返回零值，否则返回非零值，并设置全局变量 errno 为一个正值，该值可通过 perror 来解释。
int fsetpos(FILE *stream, fpos_t *pos);

//描述：返回给定流 stream 的当前文件位置。
//参数：
//返回：该函数返回位置标识符的当前值。如果发生错误，则返回 -1L，全局变量 errno 被设置为一个正值。
long int ftell(FILE *stream);

//描述： 设置文件位置为给定流 stream 的文件的开头。
//参数：
//返回：该函数不返回任何值。
void rewind(FILE *stream);


//错误处理函数
//描述：清除给定流 stream 的文件结束和错误标识符。
//参数：
//返回：这不会失败，且不会设置外部变量 errno，但是如果它检测到它的参数不是一个有效的流，则返回 -1，并设置 errno 为 EBADF。
void clearerr(FILE *stream);

//描述：测试给定流 stream 的文件结束标识符。
//参数：
//返回：当设置了与流关联的文件结束标识符时，该函数返回一个非零值，否则返回零。
int feof(FILE *stream);

//描述：测试给定流 stream 的错误标识符。
//参数：
//返回：如果设置了与流关联的错误标识符，该函数返回一个非零值，否则返回一个零值。
int ferror(FILE *stream);

//描述：把一个描述性错误消息输出到标准错误 stderr。首先输出字符串 str，后跟一个冒号，然后是一个空格。
//参数：
//返回：该函数不返回任何值。
void perror(const char *s);

#include "stdlib.h"

//内存相关函数
//描述：分配所需的内存空间，并返回一个指向它的指针。malloc 和 calloc 之间的不同点是，malloc 不会设置内存为零，而 calloc 会设置分配的内存为零。
//参数：
//返回：该函数返回一个指针 ，指向已分配大小的内存。如果请求失败，则返回 NULL。
void *calloc(size_t nitems, size_t size);

//描述：分配所需的内存空间，并返回一个指向它的指针。
//参数：
//返回：该函数返回一个指针 ，指向已分配大小的内存。如果请求失败，则返回 NULL。
void *malloc(size_t size);

//描述：释放之前调用 calloc、malloc 或 realloc 所分配的内存空间。
//参数：ptr -- 指针指向一个要释放内存的内存块，该内存块之前是通过调用 malloc、calloc 或 realloc 进行分配内存的。如果传递的参数是一个空指针，则不会执行任何动作。
//返回：
void free(void *ptr);

//描述：尝试重新调整之前调用 malloc 或 calloc 所分配的 ptr 所指向的内存块的大小。
//参数：
//返回：该函数返回一个指针 ，指向重新分配大小的内存。如果请求失败，则返回 NULL。
void *realloc(void *ptr, size_t size);

//系统相关
//描述：中止程序执行，直接从调用的地方跳出。
//参数：
//返回：
void abort(void);

//描述： 当程序正常终止时，调用指定的函数 func。您可以在任何地方注册你的终止函数，但它会在程序终止的时候被调用。
//参数：
//返回：如果函数成功注册，则该函数返回零，否则返回一个非零值。
int atexit(void(*func)(void));

//描述：立即终止调用进程。任何属于该进程的打开的文件描述符都会被关闭，该进程的子进程由进程 1 继承，初始化，且会向父进程发送一个 SIGCHLD 信号。
//参数：status -- 返回给父进程的状态值。
//返回：该函数不返回值。
void exit(int status);

//描述：搜索 name 所指向的环境字符串，并返回相关的值给字符串。
//参数：
//返回：该函数返回一个以 null 结尾的字符串，该字符串为被请求环境变量的值。如果该环境变量不存在，则返回 NULL。
char* getenv(const char* name);

//描述：把 command 指定的命令名称或程序名称传给要被命令处理器执行的主机环境，并在命令完成后返回。
//参数：
//返回：如果发生错误，则返回值为 -1，否则返回命令的状态。
int system(const char *string);

//排序
//描述： 对 nitems 对象的数组执行二分查找，base 指向进行查找的数组，key 指向要查找的元素，size 指定数组中每个元素的大小。
//数组的内容应根据 compar 所对应的比较函数升序排序。
//参数：key -- 指向要查找的元素的指针，类型转换为 void*。
//base -- 指向进行查找的数组的第一个对象的指针，类型转换为 void*。
//返回：如果查找成功，该函数返回一个指向数组中匹配元素的指针，否则返回空指针。.
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

//描述：对数组进行排序。
//参数：
//返回：该函数不返回任何值。
void * qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

//基础数学相关

//
//描述：返回 x 的绝对值。
//参数：
//返回：
int abs(int x);

//描述：把 numer（分子）除以 denom（分母）。
//参数：
//返回：该函数返回定义在 <cstdlib> 中的结构中的值，该结构有两个成员，如 div_t:int quot; int rem;。
div_t div(int number, int denom);

//描述：返回 x 的绝对值。
//参数：
//返回：
long int labs(long int x);

//描述：把 numer（分子）除以 denom（分母）。
//参数：
//返回：该函数返回定义在 <cstdlib> 中的结构中的值，该结构有两个成员，如 ldiv_t:long quot; long rem;。
ldiv_t ldiv(long int number, long int denom);

//描述：返回一个范围在 0 到 RAND_MAX 之间的伪随机数。RAND_MAX 是一个常量，它的默认值在不同的实现中会有所不同，但是值至少是 32767。
//参数：
//返回：该函数返回一个范围在 0 到 RAND_MAX 之间的整数值。
int rand(void);

//描述：播种由函数 rand 使用的随机数发生器。
//参数：
//返回：该函数不返回任何值。
void srand(unsigned int seed);

//字符串相关
//描述：返回参数 str 所指向的多字节字符的长度。
//参数：str -- 指向多字节字符的第一个字节的指针。
//n -- 要检查的字符长度的最大字节数。
//返回：如果识别了一个非空宽字符，mblen() 函数返回 str 开始的多字节序列解析的字节数。
//如果识别了一个空宽字符，则返回 0。如果识别了一个无效的多字节序列，或者不能解析一个完整的多字节字符，则返回 -1。
int mblen(const char* str, size_t n);

//描述：把参数 str 所指向的多字节字符的字符串转换为参数 pwcs 所指向的数组。
//参数：pwcs -- 指向一个 wchar_t 元素的数组，数组长度足以存储一个最大字符长度的宽字符串。
//str -- 要被转换的多字节字符字符串。
//n -- 要被转换的最大字符数。
//返回：该函数返回转换的字符数，不包括结尾的空字符。如果遇到一个无效的多字节字符，则返回 -1 值
size_t mbstowcs(wchar_t *pwcs, const char *str, size_t n);

//描述：把一个多字节序列转换为一个宽字符。
//参数：pwc -- 指向类型为 wchar_t 对象的指针。
//str -- 指向多字节字符的第一个字节的指针。
//n -- 要被检查的最大字节数。
//返回：如果 str 不为 NULL，mbtowc() 函数返回 str 开始消耗的字节数，如果指向一个空字节，则返回 0，如果操作失败，则返回 -1。
//如果 str 为 NULL，如果编码具有移位状态，则 mbtowc() 函数返回非零，如果编码是无状态的，则返回零。
int mbtowc(wchar_t *pwc, const char *str, size_t n);

//描述： 把宽字符字符串 pwcs 转换为一个 str 开始的多字节字符串。最多会有 n 个字节被写入 str 中。
//参数：str -- 指向一个 char 元素的数组，至少有 n 字节长。
//pwcs -- 要被转换的宽字符字符串。
//n -- 要被写入到 str 中的最大字节数。
//返回：该函数返回转换和写入到 str 中的字节数，不包括结尾的空字符。如果遇到一个无效的多字节字符，则返回 -1 值。
size_t wcstombs(char *str, const wchar_t *pwcs, size_t n);

//描述：把宽字符 wchar 转换为它的多字节表示形式，并把它存储在 str 指向的字符数组的开头。
//参数：str -- 一个指针，指向一个足以存储多字节字符的数组。
//wchar -- 类型为 wchar_t 的宽字符。
//返回：如果 str 不为 NULL，wctomb() 函数返回写入字节数组中的字节数。如果 wchar 不能被表示为一个多字节序列，则会返回 -1。
//如果 str 为 NULL，如果编码具有移位状态，则 wctomb() 函数返回非零，如果编码是无状态的，则返回零。
int wctomb(char *str, wchar_t wchar);


#include "stddef.h"
//定义了各种变量类型和宏。这些定义中的大部分也出现在其它头文件中。

//变量类型
ptrdiff_t //这是有符号整数类型，它是两个指针相减的结果。
size_t //这是无符号整数类型，它是 sizeof 关键字的结果。
wchar_t //这是一个宽字符常量大小的整数类型。

//库宏
NULL //

//这会生成一个类型为 size_t 的整型常量，它是一个结构成员相对于结构开头的字节偏移量。成员是由 member - designator 给定的，结构的名称是在 type 中给定的。
offset(type, member-designator)

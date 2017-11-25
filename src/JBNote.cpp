time_t;// ʱ����������

struct tm//ʱ���������
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

//������
//������
//���أ�

//cpuʹ�õ�ʱ��
//���أ�����ʹ�õĴ�����ʱ���������ܻ�ȡ��ʱ�򷵻�(clock_t)-1
clock_t clock(void);
//������ʱ���
//������
//���أ�����Ϊdouble
double difftime(time_t time1, time_t time0);
//������ʵ������ʱ������֮���ת��
//������
//���أ�
time_t mktime(struct tm *timeptr);
//��������ȡ��ǰʱ��
//�������������ֵ��Ϊ�գ��򷵻�ֵ��ֵ����ָ��Ķ���
//���أ�
time_t time(time_t *timer);
//��������ʱ���������ת��Ϊ�ַ���"Sun Sep 16 01:03:52 1973\n\0"������ascΪascii����˼�������ַ����Ĵ�����
//������
//���أ��ַ���
char * asctime(const struct tm *timeptr);
//��������ʱ����������ת��Ϊ�ַ������ȼ���asctime(ctime(const time_t* timer))
//������
//���أ�
char * ctime(const time_t *timer);
//��������timerָ���ʱ��ת����UTC��Coordinated Universal Timer����ʾ��ʱ���������
//������
//���أ���UTC�����ã�����NULL
struct tm *gmtime(const time_t *timer);
//��������timerָ���ʱ��ת���ɱ���ʱ���ʾ��ʱ���������
//������timer����ΪNULL
//���أ�
struct tm *localtime(const time_t *timer);
//ע�⣺�����ĸ�����ֵΪָ�����͵ĺ�����ָ�붼ָ��һ������ľ�̬����ʱ��������ͻ�����char���飩�����ִ�лᷢ������
//������ʱ���ʽ�������������������Ϊ��������LC_TIME�Ĳ�ͬ�������ܴ�仯
//������format������ר�ŵ�ʱ�������ʽ��ģ��printf�����������strftimeר�õ�һ��
//���أ����������ֹ�������ַ���С�ڵ���maxsize�򷵻ظ����֣����򷵻�0
size_t strftime(char *s, size_t maxsize, const char *format, const struct tm *timeptr);



#include <stdio.h>
FILE
fpos_t
_IOFBF
_IOLBF
_IONBF
BUFSIZ
FOPEN_MAX
FILENAME_MAX
L_tmpnam
SEEK_CUR
SEEK_END
SEEK_SET
TMP_MAX
stderr
stdin
stdout


//�ļ�����
//����������һ���ļ���Ҳ����ͨ�������ļ������з�����
//������
//���أ��ɹ�0���������
int remove(const char *filename);
//������
//������
//���أ�
int rename(const char *old, const char *new);
//������
//������
//���أ�
FILE *tmpfile(void);
//������
//������
//���أ�
char *tmpnam(char *s);

//�ļ�����
//������
//������
//���أ�
int fclose(FILE *stream);
//������
//������
//���أ�
int fflush(FILE *stream);
//������
//������
//���أ�
FILE* fopen(const char *filename, const char *mode);
//������
//������
//���أ�
FILE* freopen(const char *filename, const char *mode, FILE *stream);
//������
//������
//���أ�
void setbuf(FILE *stream, char *buf);
//������
//������
//���أ�
int setvbuf(FILE *stream, char *buf, int mode, size_t size);

//��ʽ�����
//������
//������
//���أ�
int fprintf(FILE *stream, const char *format, ... );
//������
//������
//���أ�
int fscanf(FILE *stream, const char *format, ... );

//������
//������
//���أ�
int printf(const char *format, ...);

//������
//������
//���أ�
int scanf(const char *format, ...);

//������
//������
//���أ�
int sprintf(char *s, const char* format, ...);

//������
//������
//���أ�
int sscanf(const char *s, const char* format, ...);

//������
//������
//���أ�
int vfprintf(FILE *stream, const char *format, va_list arg);

//������
//������
//���أ�
int vprintf(const char *format, va_list arg);

//������
//������
//���أ�
int vsprintf(char *s, const char *format, va_list arg);


//�ַ������������
//������
//������
//���أ�
int fgetc(FILE *stream);

//������
//������
//���أ�
char *fgets(char *s, int n, FILE *stream);

//������
//������
//���أ�
int fputc(int c, FILE *stream);

//������
//������
//���أ�
int fputs(const char *s, FILE *stream);

//������
//������
//���أ�
int getc(FILE *stream);

//������
//������
//���أ�
int getchar(void);

//������
//������
//���أ�
char *gets(char *s);

//������
//������
//���أ�
int putc(int c, FILE *stream);

//������
//������
//���أ�
int putchar(int c);

//������
//������
//���أ�
int puts(const char *s);

//������
//������
//���أ�
int ungetc(int c, FILE *stream);

//������
//������
//���أ�
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

//������
//������
//���أ�
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);


//�ļ���λ����
//������
//������
//���أ�
int fgetpos(FILE *stream, fpos_t *pos);

//������
//������
//���أ�
int fseek(FILE *stream, long int offset, int whence);

//������
//������
//���أ�
int fsetpos(FILE *stream, fpos_t *pos);

//������
//������
//���أ�
long int ftell(FILE *stream);

//������
//������
//���أ�
void rewind(FILE *stream);

//��������

//������
//������
//���أ�
void clearerr(FILE *stream);

//������
//������
//���أ�
int feof(FILE *stream);

//������
//������
//���أ�
int ferror(FILE *stream);

//������
//������
//���أ�
void perror(const char *s);
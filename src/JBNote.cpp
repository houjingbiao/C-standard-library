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
//����
size_t
FILE //�������ͣ���¼����������Ҫ��������Ϣ
fpos_t //�������ͣ�Ψһָ���ļ��е�ÿһ��λ������Ҫ����Ϣ
//��
NULL
_IOFBF //��Ϊsetvbuf�Ĳ���ʹ��
_IOLBF //��Ϊsetvbuf�Ĳ���ʹ��
_IONBF //��Ϊsetvbuf�Ĳ���ʹ��
BUFSIZ //չ��Ϊһ����ֵ�������ʽ��ָ����setbuf����ʹ�õĻ����С
EOF //������
FOPEN_MAX //���ͬʱ�򿪵��ļ���
FILENAME_MAX //�ļ�������
L_tmpnam //�������һ���������������������ַ�������Դ洢���� tmpnam ������������ʱ�ļ�������󳤶ȡ�
SEEK_CUR //fseek�����ĵ���������
SEEK_END//fseek�����ĵ���������
SEEK_SET//fseek�����ĵ���������
TMP_MAX //������� tmpnam ���������ɵĶ����ļ��������������
stderr //��׼���󡢱�׼����ͱ�׼�������
stdin
stdout


//�ļ�����
//������ɾ���ļ�
//������
//���أ��ɹ�0������-1������errno
int remove(const char *filename);
//�������޸��ļ���
//������
//���أ��ɹ�����0������-1����errno
int rename(const char *old, const char *new);
//������������ʱ�ļ��������رջ��߳�����ֹ��ʱ���ļ��Զ�ɾ��
//������
//���أ��ɹ�������ָ�룬����NULL
FILE *tmpfile(void);
//���������ɲ�����һ����Ч����ʱ�ļ�����
//������s��ָ���ַ������ָ�룬������ʱ�ļ������洢ΪC�ַ���
//���أ�һ��ָ��C�ַ�����ָ�룬���ַ����洢����ʱ�ļ�����s=NULLʱ����ָ��ָ��һ���ڲ����������´ε��øû������ᱻ���ǣ�
//str!=NULL���򷵻�str���������δ�ܴ����ɹ����򷵻�NULL
char *tmpnam(char *s);

//�ļ�����
//�������ر��ļ���
//������
//���أ��ɹ�����0�����򷵻�EOF
int fclose(FILE *stream);
//������ˢ���������������
//������
//���أ��ɹ�0������EOF������feof
int fflush(FILE *stream);
//���������ļ�
//������r��ֻ�����ļ�������ڣ���w��д�룬������ڣ������ԭ�ļ�����a��׷�ӣ���r+���ɶ���д���ļ�������ڣ���
//w+������һ�����ڶ�д�Ŀ��ļ�����a+����һ�����ڶ�ȡ��׷�ӵ��ļ���
//���أ��ɹ�FILEָ�룬����NULL������errno
//mode �����м�����̬�ַ��� :
//r ��ֻ����ʽ���ļ������ļ�������ڡ�
//r + �Կɶ�д��ʽ���ļ������ļ�������ڡ�
//rb + ��д��һ���������ļ�����������ݡ�
//rw + ��д��һ���ı��ļ����������д��
//w ��ֻд�ļ������ļ��������ļ�������Ϊ0�������ļ����ݻ���ʧ�����ļ��������������ļ���
//w + �򿪿ɶ�д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������������ļ���
//a �Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�����ļ�ԭ�ȵ����ݻᱻ��������EOF��������
//a + �Ը��ӷ�ʽ�򿪿ɶ�д���ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ������ ��ԭ����EOF����������
//wb ֻд�򿪻��½�һ���������ļ���ֻ����д���ݡ�
//wb + ��д�򿪻���һ���������ļ����������д��
//ab + ��д��һ���������ļ�������������ļ�ĩ׷�����ݡ�
//at + ��һ����string���ļ���a��ʾappend, ����˵д�봦���ʱ���ǽ���ԭ���ļ���������д�룬���Ǵ�ͷд�븲�ǵ���t��ʾ���ļ����������ı��ļ��� + �ű�ʾ���ļ��ȿ��Զ�Ҳ����д��
//��������̬�ַ����������ټ�һ��b�ַ�����rb��w + b��ab + ����ϣ�����b �ַ��������ߺ������Զ�����ģʽ���ļ����������b����ʾĬ�ϼ���t����rt, wt, ����t��ʾ���ı�ģʽ���ļ�����fopen()�����������ļ������S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH(0666)Ȩ�ޣ����ļ�Ȩ��Ҳ��ο�umask ֵ��
//��ЩC����ϵͳ���ܲ���ȫ�ṩ������Щ���ܣ��е�C�汾����"r+", "w+", "a+", ����"rw", "wr", "ar"�ȣ�����ע������ϵͳ�Ĺ涨��
//�����ƺ��ı�ģʽ������
//1.��windowsϵͳ�У��ı�ģʽ�£��ļ���"\r\n"�����С������ı�ģʽ���ļ�������fputs�Ⱥ���д�뻻�з�"\n"ʱ���������Զ���"\n"ǰ�����"\r"����ʵ��д���ļ�����"\r\n" ��
//2.����Unix / Linuxϵͳ���ı�ģʽ�£��ļ���"\n"�����С�����Linuxϵͳ�����ı�ģʽ�Ͷ�����ģʽ�²�������
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
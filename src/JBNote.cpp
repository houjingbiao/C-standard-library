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
//˵��
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


�ļ���д
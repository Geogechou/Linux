#include<stdio.h>
#include<time.h>
#include<unistd.h>
int main(void)
{
	//时间戳单位是秒
	time_t now_stamp=time(0);
	printf("%ld\n",now_stamp);
	struct tm* now=localtime(&now_stamp);
	//年份返回的是自1900年过去多少年，月份返回0~11
	printf("%d-%d-%d\t",now->tm_year+1900,now->tm_mon+1,now->tm_mday);
	printf("%d:%d:%d\n",now->tm_hour,now->tm_min,now->tm_sec);
	//星期返回0~6
	printf("星期%d\n",now->tm_wday);
  time_t now_stamp2=	mktime(now);
	//单位为s
	sleep(1);
	//1s=1,000,000us
	usleep(1000000);
	printf("mktime转换%ld\n",now_stamp2);

	return 0;
}

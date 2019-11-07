#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>
int main(void)
{
				struct timeval begin,end;
				gettimeofday(&begin,0);
				printf("s:%ld,ms:%ld\n",begin.tv_sec,begin.tv_usec);
				usleep(100000);
				gettimeofday(&end,0);
				printf("s:%ld,ms:%ld\n",end.tv_sec,end.tv_usec);
				printf("已经逝去:%ld\n",end.tv_usec-begin.tv_usec);
				return 0;
}

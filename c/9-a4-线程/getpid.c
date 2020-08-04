#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("本线程pid:%d\n",getpid());
	sleep(3);
	return 0;
}

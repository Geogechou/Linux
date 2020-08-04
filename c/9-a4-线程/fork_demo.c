#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("本进程编号为:%d\n",getpid());
	//fork函数会创建一个子进程，返回子进程的pid，在父进程中返回子进程pid，子进程中返回0
	int ipid = fork();
	printf("pid=%d\n",ipid);
	if(ipid!=0){
		printf("父进程的编号为:%d\n",getpid());
	}else{
		printf("子进程的编号为:%d\n",getpid());
	}
	pause();
}

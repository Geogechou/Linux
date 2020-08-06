/*
* 使用管道读取system()打印在屏幕上的信息
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void PROCESS_FUNC(int sig)
{
	printf("信号处理函数,%d\n",getpid());
	return ;
}
int main()
{
	
	FILE* pf = popen("ps -ef|grep a.out|awk 'NR==1{print $2}'","r");
	if(pf == NULL){ 
		perror("打开管道失败\n");
		return -1;
	}
	char buffer[1024];
	fread(buffer,sizeof(buffer),1,pf);
	pclose(pf);
	int pid = atoi(buffer);
	printf("read a.out pid:%d\n",pid);
	//kill函数，第一个参数为pid,pid>0则发送给对应的进程,这里发送给a.out，要求其关闭进程
	kill(pid,SIGINT);
	/*
	* kill()函数中pid=0的情况
	*/
	//注册信号处理函数
	signal(SIGUSR1,PROCESS_FUNC);
	//parent
	if(fork()>0){
		//如果pid = 0,则发送给当前进程和子进程
		kill(0,SIGUSR1);
	}else{
		//son

	}
	return 0;
}

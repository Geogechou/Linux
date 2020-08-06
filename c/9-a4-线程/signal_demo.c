#include <signal.h>
#include <stdio.h>
#include <unistd.h>

//收到信号执行的函数
void EXIT(int sig)
{
	printf("signal is:%d\n",sig);
	//可以释放资源
}
int main()
{
	//对cltr-c做处理
	signal(SIGINT,EXIT);
	//对kill命令做处理
	signal(SIGTERM,EXIT);
	sleep(1000);
	return 0;
}

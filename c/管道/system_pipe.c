/*
* 使用管道读取system()打印在屏幕上的信息
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

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
	printf("read pid:%d\n",pid);
	kill(pid,2);
	return 0;
}

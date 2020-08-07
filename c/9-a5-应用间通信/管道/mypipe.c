#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

const char string[]="welcome to unnamed pipe";
int main(void)
{
	int filedes[2];
	char inbuf[256];
	if(pipe(filedes)<0){
		perror("could not create unnamed pipe");
		exit(1);
	}
	//往管道中写数据
	write(filedes[1],string,23);
	//关闭写管道
	close(filedes[1]);
	//初始化内存，将inbuf初始化为0
	memset(inbuf,0,sizeof(inbuf));
	//从管道中读出信息，存放在inbuf中
	read(filedes[0],inbuf,23);
	//关闭读管道
	close(filedes[0]);
	printf("%s\n",inbuf);
	exit(0);

}

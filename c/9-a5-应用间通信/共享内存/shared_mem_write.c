#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main()
{
	//共享内存标识符
	int shmid;
	int key = ftok(".",0x5005);
	if(key==-1){
		perror("创建key失败\n");
	}
	//创建一块共享内存，第一个参数是一个key，用来标识共享内存的，第二个参数是size
	//第三个参数是权限，其中0666是与文件的权限相似，意味可读可写，IPC_CREAT如果不存在就创建
	if((shmid=shmget((key_t)key,1024,0666|IPC_CREAT))==-1){
		perror("0x5005 shmat failure\n");
		return -1;
	}
	//把共享内存连接到当前进程的地址空间
	//第一个参数是共享内存标识
	//第二个是指定共享内存链接到当前进程的地址位置，通常为空，操作系统来选
	//第三个参数是标志为，通常为0,返回共享内存的首地址
	char* ptext = shmat(shmid,NULL,0);
	//操作共享内存
	printf("写入前:%s\n",ptext);
	sprintf(ptext,"进程pid:%d",getpid());
	printf("写入后:%s\n",ptext);
	//把共享内存从当前进程分离
	shmdt(ptext);
	//sleep(20);
	return 0;

}

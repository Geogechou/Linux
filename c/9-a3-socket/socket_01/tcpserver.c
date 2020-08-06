#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

int init_server(int port)
{
	//避免僵尸进程, ps -ef命令后面带[defunct]的是僵尸进程，指的是子进程结束，但是没有父进程回收资源
	signal(SIGCHLD,SIG_IGN);
	//创建用于监听的socket
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	//服务器地址信息的数据结构
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	//协议族
	servaddr.sin_family = AF_INET;
	//本主机的任意ip地址，可能有多个网卡的地址
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//servaddr.sin_addr.s_addr = inet_addr("47.93.28.165"),指定本主机的唯一ip地址
	//绑定通信端口
	servaddr.sin_port = htons(port);
	if(bind(listenfd,(struct sockaddr* )&servaddr,sizeof(servaddr)) != 0){
		perror("绑定出错");
		close(listenfd);
		return -1;
	}
	//把socket设置为监听模式, 第二个参数是同时等待请求的数量
	if( listen(listenfd,5) != 0){
		perror("监听失败");
		close(listenfd);
		return -1;
	}
	return listenfd;

}
int main()
{
	int listenfd = init_server(5000);
	if(listenfd <= 0){
		perror("服务器初始化失败\n");
		return -1;
	}
	printf("服务器建立成功,开始监听\n");
	//接受客户端的链接
	int clientfd;
	int socklen;
	struct sockaddr_in clientaddr; //客户端的地址信息
	while(1){
		clientfd = accept(listenfd,(struct sockaddr *)& clientaddr, (socklen_t*)&socklen);
		if(clientfd > 0 && fork()>0){
			//父进程关闭与客户端的连接并且继续监听
			close(clientfd);
			continue;
		}else{
			//子进程关闭监听
			close(listenfd);
		}
		//与客户端通信
		char strbuffer[1024];
		while(1){
			memset(strbuffer,0,sizeof(strbuffer));
			if(recv(clientfd,strbuffer,sizeof(strbuffer),0) <= 0){
				break;
			}
			printf("接受到的信息:%s\n",strbuffer);
			sleep(3);
			strcpy(strbuffer,"ok");
			if(send(clientfd,strbuffer,strlen(strbuffer),0) <= 0){
				break;
			}
			printf("发送的信息:%s\n",strbuffer);
		}
		//关闭socket
		close(clientfd);
		//子进程返回，结束子进程
		return 0;
	}
	close(listenfd);
	return 0;
}

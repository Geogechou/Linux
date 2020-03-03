#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	//创建客户端的socket
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	//ip地址数据结构
	struct hostent* h;
	if( (h = gethostbyname("127.0.0.1")) == 0 ){
		perror("gethostbyname error\n");
		close(sockfd);
		return -1;
	}
	//把服务器地址和端口转换为数据结构
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5000);
	memcpy(&servaddr.sin_addr.s_addr, h->h_addr, h->h_length);
	//想服务器发起连接请求
	if( connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) != 0){
		perror("connect error!\n");
		close(sockfd);
		return -1;
	}

	char strbuffer[1024];
	//与服务器通信
	srand(time(0));
	for(int i=0; i<5; i++){
		memset(strbuffer,0,sizeof(strbuffer));
		int rd = rand()%1000;
		sprintf(strbuffer,"这是第%d个报文, 随机数是%d \n",i,rd);
		if(send(sockfd,strbuffer,strlen(strbuffer),0) <= 0){
			break;
		}
		printf("客户端发送信息: %s\n",strbuffer);
	}
	close(sockfd);
	return 0;
}

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <errno.h>

int main(int argc,char** argv)
{
	//创建客户端的socket
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	//ip地址数据结构
	struct hostent* h;
	if( (h = gethostbyname("www.sonydafa.com")) == 0 ){
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
	//向服务器发起连接请求
	if( connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) != 0){
		perror("connect error!\n");
		close(sockfd);
		return -1;
	}

	//读取文件
	if(argc<2){
		printf("输入一个文件的参数\n");
		return -1;
	}
	FILE* file=fopen(argv[1],"rb");
	if(file==NULL){
		perror("文件无法正确打开,\n");
		printf("%s\n",strerror(errno));
		return -1;
	}
	int size = -1;
	int send_len=-1;
	unsigned char strbuffer[1024];
	unsigned char databuffer[1024+128];
	int block_size = sizeof(strbuffer);
	memset(strbuffer,0,sizeof(strbuffer));
	memset(databuffer,0,sizeof(databuffer));
	int cnt = 0;
	while((size=fread(strbuffer,1,block_size,file))>0){
		//报文格式: 文件名:文件内容
		sprintf(databuffer,"%s:",argv[1]);
		int name_len = strlen(databuffer);
		//要用内存拷贝，不要使用strcpy()，对于二进制内容而言,strcpy失败
		memcpy(databuffer+name_len,strbuffer,size);
		size += name_len;
		printf("读取的文件总大小为:%d,文件名大小为:%d,文件大小:%d\n",
			size,name_len,size-name_len);
		if((send_len=send(sockfd,databuffer,size,0)) <= 0){
			printf("发送失败:%s\n",strerror(errno));
			break;
		}
		cnt += send_len;
		printf("客户端发送信息长度: %d,累计发送:%d\n",send_len,cnt);
		memset(strbuffer,0,block_size);
		if( recv(sockfd,strbuffer,sizeof(strbuffer),0) <= 0){
			printf("接收到的信息为空\n");
			break;
		}
		printf("服务端接收到的信息长度:%s\n",strbuffer);
		memset(strbuffer,0,sizeof(strbuffer));
		memset(databuffer,0,sizeof(databuffer));
	}
	fclose(file);
	close(sockfd);
	return 0;
}

/**
*
* socket实现简易的上传 & 下载文件，上传到目录 ~/cloudStorage,下载默认目录为~/cloudStorage
* 下载文件命令格式: wget www.sonydafa.com:5000/test.txt
* 上传文件socket信息格式: 文件名:文件内容，装载一个socket包中，需要服务端解析
* 
*/
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <sys/stat.h>
#include<stdlib.h>

#include <regex.h>


typedef enum { true = 1, false = 0 } bool;
//符合文件规则，返回true，否则返回false
bool get_fileName(char* str,char* fileName)
{
	char* pattern = "GET[ ]+/[\?]?(.*) ";
	regex_t reg;
	regcomp(&reg,pattern,REG_EXTENDED);
	regmatch_t pmatch[2];
	int status=regexec(&reg,str,2,pmatch,0);
	char keyword[32];
	if(status==0){
		for(size_t i=1;i<reg.re_nsub+1;i++) {
			memset(keyword,0,sizeof(keyword));
			//rm_so是字符串匹配的起始位置,rm_eo是字符串匹配的终止位置
			 for (int j = pmatch[i].rm_so,k=0; j < pmatch[i].rm_eo && str[j]!=' '; j++){
				keyword[k++] = str[j];
			}
		}
		regfree(&reg);
		if(strcmp(keyword,"favicon.ico")==0) return true;
		printf("匹配到的内容为:%s\n",keyword);
		strcpy(fileName,keyword);
		return true;
	}
	return false;
	
}
void run(int listenfd)
{
	//接受客户端的链接
	int clientfd;
	int socklen;
	struct sockaddr_in clientaddr; //客户端的地址信息
	clientfd = accept(listenfd,(struct sockaddr *)& clientaddr, (socklen_t*)&socklen);
	//查看客户端的ip地址
	printf("客户端已连接:%s\n",inet_ntoa(clientaddr.sin_addr));
	//与客户端通信
	char strbuffer[1024+128];
	char sockdata[1024+128];
	bool file_exist_flag = true;
	while(1){
		memset(strbuffer,0,sizeof(strbuffer));
		memset(sockdata,0,sizeof(sockdata));
		int recv_size;
		if((recv_size=recv(clientfd,strbuffer,sizeof(strbuffer),0)) <= 0){
			printf("接收到的长度为0\n");
			break;
		}
		memcpy(sockdata,strbuffer,recv_size);
		printf("接收到的长度:%d\n",recv_size);
		printf("接受到的信息:%s\n",sockdata);
		char fileName[32];
		memset(fileName,0,sizeof(fileName));
		bool infoFlag = get_fileName(strbuffer,fileName);
		if(infoFlag){
			char fullPath[64];
			memset(fullPath,0,sizeof(fullPath));
			sprintf(fullPath,"%s%s","cloudStorage/",fileName);
			printf("发送到的文件完整路径:%s\n",fullPath);
			FILE* file=fopen(fullPath,"rb");
			if(file==NULL){
				perror("打开文件失败\n");
				break;
			}
			struct stat status;
			stat(fullPath,&status);
			long fileSize = status.st_size;
			char* bag = (char*)malloc(fileSize);
			memset(bag,0,fileSize);
			int readSize = fread(bag,1,fileSize,file);
			printf("读到文件的大小:%d\n",readSize);
			if(send(clientfd,bag,readSize,0) <= 0){
				break;
			}
			free(bag);
			close(clientfd);
			//printf("发送的信息的长度:%ld\n",fileSize);
		}else{
			int i=0;
			while(sockdata[i++]!=':');
			char name[64];
			memset(name,0,sizeof(name));
			//用strncpy复制二进制文件容易出错,使用memset可以避免
			if(i>1)
				memcpy(name,sockdata,i-1);
			int len=strlen(name);
			//填充一个前缀，目录名
			for(int i=len-1;i>=0;i--)
				name[i+13]=name[i];
			char prefix[13];
			strcpy(prefix,"cloudStorage/");
			memcpy(name,prefix,13);
			printf("获取到报文中的文件名:%s,i=%d\n",name,i);
			if(file_exist_flag==true && access(name,F_OK)==0){
				remove(name);
			}
			FILE* file = fopen(name,"ab");
			fwrite(sockdata+i,1,recv_size-(len+1),file);
			fclose(file);
			char send_msg[16];
			sprintf(send_msg,"%d",recv_size);
			int sd_size=send(clientfd,send_msg,sizeof(send_msg),0);
			file_exist_flag = false;
			
		}
	}
	printf("关闭连接\n");
	close(clientfd);
	file_exist_flag = true;
}
int main()
{
	//创建用于监听的socket
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	//服务器地址信息的数据结构
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	//协议族
	servaddr.sin_family = AF_INET;
	//本主机的任意ip地址
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//绑定通信端口
	servaddr.sin_port = htons(5000);
	if(bind(listenfd,(struct sockaddr* )&servaddr,sizeof(servaddr)) != 0){
		perror("绑定出错");
		close(listenfd);
		return -1;
	}
	int timeout = 1000;
	setsockopt(listenfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(int));
	setsockopt(listenfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(int));
	//把socket设置为监听模式, 第二个参数是同时等待请求的数量
	if( listen(listenfd,5) != 0){
		perror("监听失败");
		close(listenfd);
		return -1;
	}
	printf("服务器建立成功,开始监听\n");
	while(1){
		run(listenfd);
	}
	//关闭socket
	close(listenfd);
	return 0;
}

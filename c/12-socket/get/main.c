/**
 * An easy HTTP GET C program in windows 10 platform
 * But some website return HTTP 301, don't know why
 */
#include <stdio.h>
#include<winsock2.h>
#include<stdlib.h>
#include<windows.h>
//parameter1 is domain name, param2 is GET path
//keep download page into Desktop, filename is download.html
void spider(const char* host,const char* path)
{
    int i;
    char* buffer=(char*)malloc(8192*sizeof(char));
    SOCKET fd=socket(PF_INET,SOCK_STREAM,0);//PF_INET stand for Protocol Family internet
    SOCKADDR_IN addr;
    addr.sin_family=AF_INET;//AF_INET stand for Address Family internet
    addr.sin_addr.S_un.S_addr=0;
    addr.sin_port=htons(0);
    i=bind(fd,(struct sockaddr* )(&addr),sizeof(SOCKADDR_IN));
    //握手
    //根据域名?得ip地址
    struct hostent*p=gethostbyname(host);
    char* host_ip=inet_ntoa(*(struct in_addr*)p->h_addr_list[0]);
    printf("addr is:%s\n",host_ip);
    addr.sin_addr.S_un.S_addr=inet_addr((const char*)host_ip);
    addr.sin_port=htons(80);
    i=connect(fd,(struct sockaddr*)(&addr),sizeof(SOCKADDR_IN));
    if(i<0){
        printf("socket ?接出?");
        exit(-1);
    }
    i=sprintf(buffer,
              "GET %s HTTP/1.1\r\n"
              "Accept: text/html,*/*\r\n"
              "Host: %s\r\n"
              //"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:67.0) Gecko/20100101 Firefox/67.0\r\n"
              "Connection: Close\r\n"
              "\r\n"
              ,path,host);

    printf("head is:\n%s\n",buffer);
    int n=send(fd,buffer,(int)strlen(buffer),0);
    if(n==i){
        printf("response\n");
        FILE* file;
        char *homePath = getenv("HOMEPATH");
        char* desktop="\\Desktop\\";
        char* fileName="download.html";
        unsigned len=strlen(homePath)+strlen(desktop)+strlen(fileName);
        char* fullPath=(char*)malloc(sizeof(char)*len);
        sprintf(fullPath,"%s%s%s",homePath,desktop,fileName);
        printf("fullPath: %s\n",fullPath);
        file=fopen(fullPath,"w+");
        do{
            if(i<=0) break;
            i=recv(fd,buffer,8191,0);
            buffer[i]='\0';
            //printf("%s",buffer);
            fprintf(file,(const char*)buffer);
        }while("more");
        printf("response end\n");
    }
    closesocket(fd);
    free(buffer);
}
void modify_file(const char* path)
{
    FILE* file=fopen(path,"rw");
    if(file==NULL){
        printf("open failure\n");
    }
    char buffer[1024];
    char utf[1024];
    while(fgets(buffer,1024,file)){
        printf("%s",buffer);
    }
    fclose(file);
}
int main(int argc,char** argv,char** env) {

    WSADATA wsadata;
    WSAStartup(0x0202,&wsadata);
    const char* host="www.baidu.com";
    const char* path="/";
    spider(host,path);
    WSACleanup();
    return 0;
}
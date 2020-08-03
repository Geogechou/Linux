#include <stdio.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
	struct hostent* h;
	h = gethostbyname("www.sonydafa.com");
	if(h==NULL){
		perror("获取hostent失败\n");
		return -1;
	}
	printf("hostname:%s\n",h->h_name);
	int i=0;
	//读出ip地址
	char* ip=inet_ntoa(*(struct in_addr*)*h->h_addr_list);
	printf("ip:%s\n",ip);
	return 0;
}

#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
/*
 *程序读取list.txt文件，若第一个单词与当前用户相等，就打印出来
 ×否则就忽略
 ×用于文件s权限
 * */

/*
 *getlogin() in unistd.h
 *fopen() in stdio.h
 *char* fgets(char* buf,int bufsize,FILE* stream)
 *int sscanf(const char* str,const char* format,buf), read a int/char/string from string
 *strcmp(const char * str1,const char* str2)
 * str1==str2,return 0,else if str1<str2 return negative
 * else return positive
 * exit() in stdlib.c
 * */
int main(void)
{
	FILE* f;
	char line[512],name[64],*username;
	if((f=fopen("list.txt","r"))==NULL){
		printf("****ERROR:Open file %m\n");
		exit(1);
	}
	username=getlogin();
	while(fgets(line,sizeof(line),f)){
		if(line[0]=='#')
			printf("%s",line);
		else if(sscanf(line,"%s",name)>0&&strcmp(name,username)==0)
			printf("%s",line);
	}
	return 0;
}

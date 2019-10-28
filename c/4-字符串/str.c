#include<stdio.h>
#include<string.h>
int main(void)
{

				char str[21];
				//init string, set 0
				memset(str,0,sizeof(str));
				//将字符串常量复制到str开始的内存中
				//strcpy()会在字符串结尾置0
				//char* strcpy(char* dest, const char src), 返回dest
				strcpy(str,"strcpy copy");
				//复制前n个字符,char* strncpy(char* dest,const char src,size_t n)
				//strncpy()如果len(str)>n不会在dest[n]='\0',len(src)<=n,那么在后面追加'\0'
				strncpy(str,"hello",5);
				//提前将str[2]改为字符串的结尾标志,即为'\0'
				//str[2]=0;
				//sprintf(str,"Hello string");
				//%10s,意为一共输出10个宽度,-10为左对齐,10为右对齐
				printf("%10s\n",str);

				//字符串相关库函数
				char str2[21]="Hello Docky!";
				//strlen(char str)
				int len=strlen(str2);
				printf("%s---len:%d\n",str2,len);
				//strcat(char* des,const char src);
				strcat(str2,"Monkey!");
				printf("%s\n",str2);
				//strncat(char* dest,const char* src,size_t n),拼接n个字符
				char p[10]="Tocky";
				//两者都可以
				//strncat(str2,"Tocky",3);
				strncat(str2,p,3);
				printf("%s\n",str2);
				//int strcpy(char* str1,char* str2),相等返回0,str1>str2,返回正数,小于返回负数
				//同样还有strncpy()
				printf("%s cmp %s = %d\n",str,str2,strcmp(str,str2));
				//char* strchr(char* str,char ch),返回字符串str中字符ch的地址
				char* startI=strchr(str2,'T');
				printf("%s 中出现%c的位置是%s\n",str2,'T',startI);
				//strrchr()与strchr()类似,是在字符串最右面找ch的地址
				//char* strstr(char* str,char* str2),在字符串str中找str2,返回找到的地址
				char* str3=strstr("To the wr","the");
				if(str3)		printf("%s\n",str3);

				return 0;
}

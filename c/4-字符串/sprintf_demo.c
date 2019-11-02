#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
				char str[256];
				//格式化拼接字符串，比printf()多一个参数，第一个参数为地址
				sprintf(str,"%s%d%s%s","the number :",10,"二进制是","1010");
				printf("%s\n",str);
				//C语言续行的方式
				const char* name="alex"\ 
                         "Nom III";
				//或者这样续行
				const char* title="Professor\
Princeton";
				printf("%s\n%s\n",name,title);

				return 0;
}

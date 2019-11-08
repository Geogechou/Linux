#include<stdio.h>
//包括errno.h头文件，函数出错会把错误码记录在全局变量errno中
#include<errno.h>
//strerror()函数，将错误码转换为具体的文字描述
#include<string.h>
int main()
{
				int res=remove("nowhere");
				if(res!=0){
					printf("%d-->%s\n",errno,strerror(errno));
				}
				return 0;
}

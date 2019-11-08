#include<string.h>
#include<stdio.h>

int main(void)
{
		//系统中一共定义了130多种错误代码
		for(int errno=0;errno<150;errno++){
						printf("%d:%s\n",errno,strerror(errno));
		}
		return 0;
}

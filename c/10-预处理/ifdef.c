#include<stdio.h>
#define LINUX "ubuntu"

int main(void)
{
		//如果定义了LINUX这个宏执行if下面，否则执行else
		#ifdef LINUX
		printf("这是,%s\n",LINUX);
		#else
		printf("未知系统\n");
		#endif
		return 0;
}

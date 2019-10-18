#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//atoi()在stdlib.h中
int main()
{
		char str[30];
		strcpy(str,"12345");
		//将字符串转换为int
		int n=atoi(str);
		//将字符串转换为long类型
		long money=atol("166723232133232323");
		printf("%d\n",n);
		printf("%ld\n",money);
		long i=-100022;
		printf("long abs=%ld\n",labs(i));
		//随机数种子
		srand(time(0));
		for(int i=0;i<10;i++){
				printf("rand: %d\n",rand());
		}
		return 0;
}

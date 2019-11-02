#include<stdio.h>
#include<string.h>
struct s_man{
		char name[21];
		int age;
		int hegiht;
};
int main(void)
{
				struct s_man peter;
				//结构体初始化为0
				memset(&peter,0,sizeof(peter));
				strcpy(peter.name,"peter");
				peter.age=10;
				printf("name is:%s\n",peter.name);
				printf("%lu,int=%lu\n",sizeof(peter),sizeof(int));

				struct s_man tom;
				//内存的拷贝
				memcpy(&tom,&peter,sizeof(peter));
				printf("tom's name=%s,tom'p=%p,peter'p=%p\n",tom.name,&(tom.name),
				&(peter.name));
				return 0;
}

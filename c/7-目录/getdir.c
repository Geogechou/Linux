#include<stdio.h>
//getcwd()的头文件
#include<unistd.h>
#include<string.h>
int main(void)
{
		char dir[256];
		memset(dir,0,sizeof(dir));
		getcwd(dir,sizeof(dir)/sizeof(char));
		printf("当前目录是:%s\n",dir);
		int status=chdir("/usr/include");
		if(status==0)
						printf("切换目录成功\n");
		getcwd(dir,sizeof(dir)/sizeof(char));
		printf("当前目录是:%s\n",dir);
		return 0;
}

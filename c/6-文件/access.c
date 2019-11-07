#include<stdio.h>
#include<unistd.h>
int main(int argc,char** argv)
{
				if(argc<2){
					printf("参数1:输入要访问的文件\n");
					return -1;
				}
				int status=access(argv[1],F_OK);
				status==0?printf("文件存在\n"):printf("文件不存在\n");
				return 0;
}

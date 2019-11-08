#include<stdio.h>

int main(int argc,char** argv)
{
				if(argc<3){
								printf("参数1:原文件路径, 参数2:mv之后的路径\n");
								return -1;
				}
				int res=rename(argv[1],argv[2]);
				res==0?printf("更改成功\n"):printf("更改失败\n");
				return 0;
}

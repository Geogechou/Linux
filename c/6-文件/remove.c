#include<stdio.h>
int main(int argc,char** argv)
{
	if(argc<2){
			printf("参数1:要删除的文件名\n");
			return -1;
	}
	remove(argv[1]);
	return 0;
}

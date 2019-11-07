#include<stdio.h>
//rmdir的头文件
#include<unistd.h>

int main(int argc,char** argv)
{
	if(argc<2){
		fprintf(stderr,"参数：请给出要删除的目录名\n");
		return -1;
	}
	rmdir(argv[1]);
	return 0;
}

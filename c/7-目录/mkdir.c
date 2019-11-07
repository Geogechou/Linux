#include<stdio.h>
//mkdir()的头文件
#include<sys/stat.h>
int main(int argc,char** argv)
{
				if(argc<2){
						fprintf(stderr,"参数：给出要创建的目录\n");
						return -1;
				}
				mkdir(argv[1],00755);
				return 0;
}

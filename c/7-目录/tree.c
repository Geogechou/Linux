#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
/*
*该程序实现递归遍历目录下所有文件
*/
int readDir(char* dirname)
{
		DIR* dir=opendir(dirname);
		if(dir==0){
			fprintf(stderr,"打开目录失败，请检查目录参数是否正确,目录名是%s\n",dirname);
			return -1;
		}
		//修改当前目录
		if(chdir(dirname)!=0){
				fprintf(stderr,"切换目录失败\n");
		}
		struct dirent* curr;
		while(curr=readdir(dir)){
				//d_name是文件/目录名,d_type是文件的类型8为普通文件,4为目录文件
				char* name=curr->d_name;
				printf("%s\t%d\n",curr->d_name,curr->d_type);
				if(curr->d_type==4 && (strcmp(name,".") &strcmp(name,".."))){
								//进入子级别目录
								chdir(name);
								readDir(".");
								//返回上级目录
								chdir("..");
				}
		}
		closedir(dir);
}
int main(int argc, char** argv)
{
		if(argc<2){
			fprintf(stderr,"参数1：要显示的目录名\n");
			return -1;
		}
		readDir(argv[1]);
		return 0;
}

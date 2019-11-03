#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
/*
this program is print a directory all sub-directory
exit() in stdlib.h
errno in errno.h
dir operation in dirent.h

*/
int main(int argc,char** argv)
{
		DIR *dir;
		struct dirent* entry;
		if(argc<2){
			printf("Usage: %s <dirname>\n",argv[0]);
			exit(1);
		}

		for(int i=1;i<argc;i++){
			dir=opendir(argv[i]);
			if(dir==NULL){
				//errno对应两个格式符号%d与%m
				printf("open directory [%s] %d:%m\n",argv[1],errno);
				return 1;
			}
			//print all inode and name
			while((entry=readdir(dir))!=NULL)
				printf("%ld\t%s\n",entry->d_ino,entry->d_name);
			closedir(dir);
		}

		return 0;

}

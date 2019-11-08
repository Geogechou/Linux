#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
int main(int argc,char** argv)
{
				if(argc<1){
					printf("参数1：文件名\n");
					return -1;
				}
				struct stat status;
				//stat(char* path,struct stat* stat),成功返回0，失败返回-1
				if(stat(argv[1],&status)!=0) {
								printf("文件不存在\n");
								return -1;
				}
				long size=status.st_size;
				printf("文件的大小为:%ld\n",size);
				struct tm* mtime=localtime(&(status.st_mtime));
				printf("文件最后修改的时间为:%d-%d-%d %d:%d:%d\n",
					mtime->tm_year+1900,mtime->tm_mon+1,mtime->tm_mday,
						mtime->tm_hour,mtime->tm_min,mtime->tm_sec);
				return 0;
}

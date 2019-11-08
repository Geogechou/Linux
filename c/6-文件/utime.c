#include<sys/time.h>
#include<utime.h>
#include<stdio.h>
#include<time.h>

int main(int argc,char** argv)
{
		if(argc<2){
			printf("参数1:访问的文件路径\n");
			return -1;
		}
		struct utimbuf tbuf;
		tbuf.actime=time(0);
		tbuf.modtime=time(0);
		//修改文件访问时间和文件修改时间
		utime(argv[1],&tbuf);
		return 0;
}

#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

/*
fcntl.h, define open(), shutdown(), etc function.
errno.h, define errno
*/
int main(char argc,char*argv[])
{

		int fd;
		//open a file, fd is return value, when open fail, fd=-1
		fd=open(argv[1],O_WRONLY);
		if(fd==-1){
			//%m, print error message
			printf("error %d: %m\n",errno);
			//strerror(), passing  errno, return error message string
			printf("error [%s]\n",strerror(errno));
		}
		return 0;
}

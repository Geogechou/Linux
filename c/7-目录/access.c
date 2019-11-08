#include<stdio.h>
#include<unistd.h>

int main(int argc,char** argv)
{
	//access(const char*path,int mode)
		if(argc<2){
			printf("参数1:文件的路径名\n");
			return 0;
		}

		if(access(argv[1],R_OK)==0){
				printf("该文件有可读权限\n");
    }
		if(access(argv[1],F_OK)==0){
				printf("该文件存在\n");
		}
		if(access(argv[1],W_OK)==0){
				printf("该文件有可写权限\n");
		}
		if(access(argv[1],X_OK)==0){
				printf("该文件有可执行权限\n");
		}
		return 0;
}

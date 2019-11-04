#include<stdio.h>
#include<string.h>
/*
*文本文件的读
*/
void read_file(const char* path)
{
		//文本文件的读写模式rw
    FILE* file=fopen(path,"rw");
    if(file==NULL){
        printf("open failure\n");
				return ;
    }
    char buffer[8];
    char utf[1024];
		memset(utf,0,sizeof(utf));
		//fgets(char* buffer,size_t size,FILE*  file)
		//如果读取完了，返回空
    while(fgets(buffer,8,file)){
        printf("%s\n",buffer);
				strcat(utf,buffer);
    }
		printf("\n");
    fclose(file);
		printf("整个文件为: %s\n",utf);
}
int main(int argc, char** argv)
{
	if(argc<2) printf("请输入文件名\n");
	read_file(argv[1]);
	return 0;
}


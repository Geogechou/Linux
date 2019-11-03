#include<stdio.h>

void read_file(const char* path)
{
    FILE* file=fopen(path,"rw");
    if(file==NULL){
        printf("open failure\n");
				return ;
    }
    char buffer[1024];
    char utf[1024];
		//fgets(char* buffer,size_t size,FILE*  file)
    while(fgets(buffer,1024,file)){
        printf("%s",buffer);
    }
		printf("\n");
    fclose(file);
}
int main(int argc, char** argv)
{
	if(argc<2) printf("请输入文件名\n");
	read_file(argv[1]);
	return 0;
}


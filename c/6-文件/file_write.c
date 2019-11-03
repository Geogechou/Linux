#include <stdio.h>

int main(int argc,char** argv) {
		if(argc<2){
						printf("file name shouldn't been null\n");
						return 0;
		}
    FILE* stream;
    //a+的模式是，在append的情况上增加读的权限
		stream=fopen(argv[1],"a+");
		//fprintf(FILE* file, ...args)与sprintf()参数相似
    fprintf(stream,"hello file,你好 文件,再见吧%d\n",100);
    fclose(stream);
    return 0;
}

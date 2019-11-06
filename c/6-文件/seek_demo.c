 //long ftell(FILE* file)返回当前文件位置
 //void rewind(FILE* file)将文件位置指针移动到开头
 //offset为正数时候，往后面移动，负数时，向前面移动
 //orgin,0表示文件开始，1表示当前位置，2表示文件末尾
 //int fssek(FILE* file,long offset,int origin);
# include<stdio.h>
int main(int argc, char** argv)
{
				if(argc<2){
					fprintf(stderr,"输入参数,文件名\n");
					return -1;
				}
				FILE* file=fopen(argv[1],"a+");
				if(file==NULL){
					fprintf(stderr,"文件打开失败\n");
					return -1;
				}
				fseek(file,5,0);
			  char str[]="append something";
				fwrite(str,1,sizeof(str),file);
				//重新移到文件头
				rewind(file);
				printf("文件重新定位:%ld\n",ftell(file));
				char buff[8];
				while(fread(buff,1,sizeof(buff),file)){
					printf("读到的内容是%s\n",buff);
				}
				return 0;
}

#include<stdio.h>
/*
*二进制文件的读取，主要用fread()函数
*/
int main(int argc,char** argv)
{
		if(argc<2){
				printf("请输入要读取的二进制文件名\n");
				return -1;
		}
		FILE* file=fopen(argv[1],"rb");
		if(file==NULL){
				printf("文件读取失败，检查路径是否出错\n");
				return -1;
		}
		char p[32];
		//fread()返回读取到的块数目
		//参数依次是,存放的地址,每块的字节数(习惯设置为1)，块数目，文件流
		int size=-1;
		int sum =0 ;
		while((size= fread(&p,1,sizeof(p),file))>0){
			sum += size;
		}

		printf("读取的文件总大小为:%d\n",sum);
		return 0;
}

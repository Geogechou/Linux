#include<stdio.h>
/*
*二进制文件的写入
*如下这个例子,hexdump bwrite.dat的文件内容如下
*其中第一列是长度,由于写的是int型的值，所以四个字节，也就是八位16进制数是一个int
*1023就是03ff,15就是f
*0000000 03ff 0000 000f 0000                    
*0000008
*
*/
int main(void)
{
		FILE* file;
		file=fopen("bwrite.dat","wb");
		if(file==0){
			printf("文件打开失败\n");
			return -1;
		}
		int max=1023;
		//fwrite(const void* ptr,size_t size,size_t nmemb,FILE* stream)
		//第一个参数是要写的内容的指针，第二个参数size是每块有多少个字节长
		//第三个参数是要写多少块，第四个是文件流
		//因此第四个参数可以用sizeof(ptr),第三个参数用1即可
		fwrite(&max,1,sizeof(max),file);
		int min=15;
		fwrite(&min,1,sizeof(min),file);
		fclose(file);
		return 0;
}

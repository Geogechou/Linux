#include<stdio.h>
#include<errno.h>

int main()
{
				int res=remove("nowhere");
				if(res!=0){
					//提供给函数一个概述，perror()打印具体错误原因
					perror("删除文件失败");
				}
				return 0;
}

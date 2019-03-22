## lseek()函数用于改变文件当前偏移量
1. 头文件

        #include<unistd.h>
2. 函数原型

        off_t lseek(int filedes,off_t offset,int origin);
3. 参数说明
1. filedes,文件描述符
2. offset，偏移量
3. origin为SEEK_SET,则offset从文件开头算起
7. orign为SEEK_CUR,则offset从当前算起。
8. origin为SEEK_END，则从offset从文件末尾算起

## 文件系统特点
1. 根目录文件系统
2. 文件名区分大小写
3. 目录路径使用正斜杠/
4. 没有驱动器号,一切文件都在root目录下
5. 无独占访问权限(可以修改和删除被其他应用程序访问的文件)
## 文件API
1. open()
2. create()
3. close()
4. read()
5. write()
## open()函数

    头文件
    #include<sys/types.h>
    #include<sys/stat.h>
    #include<fcntl.h>
    函数原型
    intopen(constcharpathname,int flags);
    intopen(constcharpathname,int flags,mode_t mode);
1. 函数的返回值是文件描述符，如果打开文件成功返回一个正整数，否则返回-1    
### 打开文件操作的主标志

主标志是互斥的，使用其中一种则不能再使用另外一种。除了主标志以外，还有副标志可与它们配合使用，副标志可同时使用多个，使用时在主标志和副标志之间加入按位与（|）运算符.
|参数|说明|
|--------|---------|
|O_RDONLY|以只读的方式打开文件|
|O_WRONLY|以只写的方式打开文件|
|O_RDWR|以只读写方式打开文件|
### 打开文件操作的副标志

|参数|说明|
|---|----|
|O_APPEND|读写文件从文件尾部开始移动，所写入的数据追加到文件尾|
|O_CREAT|若路径中的文件不存在则自动建立该文件|
|O_EXCL|如果与O_CREAT同时设置，此指令会去检查文件是否存在，文件若不存在则建立该文件，否则将导致打开文件错误。此外，若O_CREAT与O_EXCL同时设置，并且将要打开的文件为符号连接，则将导致打开文件失败|   


        #include<stdio.h>
        #include<sys/types.h>
        #include<sys/stat.h>
        #include<fcntl.h>
        #include<stdlib.h>
        #define FILE_PATH "test.txt"
        int main(void){
        int fd;
        if(fd=open(FILE_PATH,O_RDWR|O_CREAT|O_EXCL,0777)<0){
            printf("open error\n");
            exit(-1);
        }else
        printf("open success.\n");

        return 0;
        }
程序打开一个"test.txt"文件,若不存在,则创建,并赋予权限是777,并返回正数;需要注意的是,如果文件存在,则回一直返回-1;
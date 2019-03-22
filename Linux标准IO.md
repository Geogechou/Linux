## 标准IO
标准IO库是ANSI C规范的一部分，函数原型在stdio.h中定义。对底层IO系统调用进行了一部分的封装。
## fopen函数
1. 功能：打开一个指定文件
2. 函数原型

        FILE * fopen(const char* restrict pathname,const char* restrict type);

![](https://github.com/georgezhou314/imageRepo/raw/master/linux/%E6%96%87%E4%BB%B61.png)
## fdopen函数
1. 功能
取一个现存的文件描述符，并使一个标准IO流与该描述符相结合，常用于由创建管道及网络通信通道函数返回的描述符

1. 函数原型

        File* fdopen(int fd,const char*type);
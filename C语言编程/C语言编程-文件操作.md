## Linux第四周
---
## creat函数
1. 头文件   

        #include<sys/>types.h>
        #include<sys/>stat.h>
        #include<fcntl.h>
2. 函数原型

        int creat(const char*pathname,mode_t mode);
        //mode就是Linux中的权限，例如0777
3. 返回值
    若有错误则返回-1，成功则返回新的文件的描述词。
## close关闭文件
1. 头文件

        #include<unistd.h>
2. 函数原型

        int close(int fd);
        //fd是之前create返回的描述符
3. 返回值

        若文件顺利关闭返回0，错误返回-1
## read由打开的文件读取数据
1. 头文件

        #include<unistd.h>
2. 函数原型

        ssize_t read(int fd,void* buf,size_t count)
3. 函数说明
## write写入函数
1. 头文件

        #include<unistd.h>
2. 函数原型

        ssize_t write(int fd,const void* buf,size_t count);
3. 函数说明
    函数会把指向buf的count个字节写入fd文件中。

//没有实践，不清楚
## ioctl(设备驱动程序中对设备的IO通道进行管理)
1. 头文件

        #include<sys/ioctl.h>
2. 定义函数

        int ioctl(int fd,int cmd,...)
3. 函数说明

        ioctl()能对一些特殊的文件(主要是设备)进行一些底层参数的操作。许多字符设备都使用ioctl请求来完成对设备的控制。
4. 返回值   
 成功返回0，失败返回-1       
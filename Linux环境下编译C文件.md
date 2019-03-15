## gcc编译过程
1. 源文件
2. 预处理
3. 编译
4. 汇编
5. 链接
6. 可执行
## gcc编译单文件,生成.out文件
    gcc linux_c.cpp
    //默认输出linux_c.out可执行文件
    ./linux_c.out就可以执行
### gcc linux_c.cpp -o linux_c
    把linux_c.cpp编译为linux_c可执行文件
## gcc编译多个文件
### 编译
1. gcc -c fb.cpp
2. gcc -c Linux_C.cpp
3. gcc -c sayhello.cpp
### 链接目标文件,生成可执行文件
1. gcc fb.o Linux_C.o sayhello.o -o exe   
exe为最终的可执行文件
## -D宏定义选项
等同于代码中的#define PI语句,但是-D定义的宏作用于所有的源文件   
1. 例子   


        #define PI 3.1415
        gcc -DPI=3.1415 main.c
## -l头文件搜索路径
如果用户的头文件不再gcc的搜索路径中,可以用此选项指定额外的搜索路径
1. 例子   

        gcc helloworld.c -l /usr/include -o helloworld
        //将/usr/include加入到文件的头文件的搜索路径中
## 警告选项
1. -Wno-option关闭警告
2. -w禁止所有警告
3. -Wall 打开所有警告
## 库文件
>静态库和动态库的区别,静态库编译集成在自己的代码中,动态库运行时实时调用.
## gdb是GNU计划开发的程序调试工具


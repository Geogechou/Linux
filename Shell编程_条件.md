## Shell编程

### if条件判断

*shell中条件判断，判定一条命令是否执行成功。命令执行的返回码，0表示成功，非0表示失败。可以把命令执行结束后的返回码理解为出错代码*

**如果代码中的main()函数没有return一个确定的值，返回码就是随机值，不可来做条件判断，如果程序调用exit()导致进程终止，exit函数的返回值是0~255**

**$?**,shell中自定义的变量，上一命令的返回码，用管道线连接在一起的若干命令，进行条件判断时以最后一个命令执行的返回码为准。

### 复合逻辑

*&&*,*||*两个文件

&&判断条件，当某一命令返回码为0，即表示真，若是其他数字，则表示假；
```c
#include<stdlib.h>
#include<stdio.h>
//如果是奇数，返回0,如果是偶数返回1
int main(int argc,char**argv){

        int a=argc<2?0:atoi(argv[1]);
        //only store the first param from command line input
        return a%2==0?1:0;
}

```

在shell中可以判断

`./isodd.out && echo odd_number`

*这条命令中，返回值为0的时候，&&会执行，并打印odd_number;返回值为1时，与不会执行,不打印任何消息*




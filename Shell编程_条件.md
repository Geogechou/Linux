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

## shell中的test命令

test用于文件判断，例如`test -d cpp_files`,是否是一个目录

与之等价的语法是`[ -d cpp_files ]`,用[]来标识，[]需要与判断内容相隔一个空格。

* 文件特性检测
  *  -f 普通文件
  * -d 目录文件
  * -r 可读
  * -w 可写
  * -x 可执行
  * -s size>0

```shell
test -d cpp_files && echo this is a directory
```

### 逻辑运算

* ! 非
* -o 或
* -a 与

### 判断字符串

```shell
str1="abc";
# 在用[]判断的时候，括号左右需要空格，等号判断时，也需要空格
[ $str1 = "abc" ] && echo str1 is abc;
```

### 命令组合用  {   }

{}和其他语言的程序段类似，还是原来的子shell

() 是新启动一个子shell，不会修改当前shell的内容

使用{}时，多行并未一行不要漏掉必须的空格和分号

```shell
[ -f core ] && { echo "rm core"; rm core; }
```


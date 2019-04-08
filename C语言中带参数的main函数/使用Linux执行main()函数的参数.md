使用Linux执行main()函数的参数

`./withargs.out 1 2 3 455 66|tee withargs.txt`

将程序运行结果写到withargs.txt文件中中

`int main(int argc,char**argv,char**env);`

其中argc表示输入传入参数的个数，比实际的传入的个数多1个，最后一个是null，argv是一个二维数组，是字符串数组，env是环境变量参数，用ubuntu做实例，大约有60多个参数，最后一个同样也是null
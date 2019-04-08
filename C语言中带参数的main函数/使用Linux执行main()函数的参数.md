使用Linux执行main()函数的参数

`./withargs.out 1 2 3 455 66|tee withargs.txt`

将程序运行结果写到withargs.txt文件中中

`int main(int argc,char**argv,char**env);`

* 其中argc表示输入传入参数的个数,对于示例来说，argc=6;

* argv是一个二维数组，是字符串数组，argv[0]是当前的执行程序的名称，对于这条程序就是*./withargs.out*

  *argv[1]=1;argv[2]=2;argv[3]=3;argv[4]=455;argv[5]=66;argv[6]=null;*

* env是环境变量参数，用ubuntu做实例，大约有60多个参数，最后一个同样也是null


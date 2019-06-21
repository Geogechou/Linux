* <a href="#id0">Bash中的变量</a>
* <a href="#id1">echo</a>
* <a href="#id2">read：读取用户的输入</a>
* <a href="#id3">环境变量</a>
* <a href="#id4">shell中的命令替换，``</a>
* <a href="#id5">shell内部变量：位置参数</a>
## 变量
<h3 id="id0">Bash中的变量</h3>
* 变量赋值

赋值作为单独的一条命令，等号两侧不允许多余的空格

`addr=20.1.1.254`

赋值时，如果等号右侧字符串中含有特殊字符，用引号括起来

`unit="BeiJing University"`

* 引用变量

`$addr`或者`${addr}`

引用未定义的变量，变量值为空字符串

`set -u`,执行该指令，当引用一个未定义的变量时，会产生一个错误

`set +u`，执行该指令，当引用一个未定义的变量时，认为是一个空字符串

<h3 id="id1">echo</h3>
格式`echo arg1 arg2 arg3`

打印个命令行参数，每两个间用一个空格分开，最后打印换行符

<h3 id="id2">read：读取用户的输入</h3>

```shell
echo "enter ip addr"
# 保存在addr变量中
read addr
# 打印addr变量
echo your addr is : $addr
```

<h3 id="id3">环境变量</h3>
内部命令export，局部变量转换为环境变量

`export JAVA_HOME`,将JAVA_HOME转换为环境变量

环境变量配置文件*/etc/profile*

PATH，命令查找路径

HOME，用户主目录路径名

TERM，终端类型

`env`命令，列出环境变量以及其值

<h3 id="id4">`(grave accent)</h3>

* shell中的命令替换

  ```shell
  #以命令date的stdout替换`date`
  now=`date`
  ```

  这种方式的另外一种写法是，`echo $(date)`,来调用date命令

* linux中方便计算

  ```shell
  # 用expr来计算，需要注意空格，比较麻烦
  frames=`expr 5 + 13`
  echo "frame is:" $frames
  # 通过管道用bc命令来计算
  num=`echo 12+1|bc`
  echo num is  $num
  ```

<h3 id="id5">shell内部变量：位置参数</h3>

* $0，脚本文件本身的名字

* $1 ，命令行第一个参数

* $2，命令行第二个参数(类推第三个等等)

* $#，命令行参数的个数

  ```shell
  test.sh
  echo "\$# is " $#
  -----
  # 命令行输入带参数运行
  # $#为3
  $: ./test.sh 1 2 3
  $: 3
  ```

* $*，用在将参数传递给其他命令，将多个参数串连起来，作为一个整体参数

* $@，用在将参数传递给其他命令，传递多个参数

  ```shell
  echo "exec \$* replace"
  # args是一个可执行程序，其程序作用是将输入参数打印出来
  ./args "$*"
  echo "exec \$@ replace"
  ./args "$@"
  -----#开始实时运行-------
  $ ./comm* 1 2 3 4 5|xsel
  
  exec $* replace
  argc is:2
  0-th arg is: ./args
  1-th arg is: 1 2 3 4 5
  exec $@ replace
  argc is:6
  0-th arg is: ./args
  1-th arg is: 1
  2-th arg is: 2
  3-th arg is: 3
  4-th arg is: 4
  5-th arg is: 5
  ```

  ### 元字符(特殊字符)

  * 空格，制表符：命令行参数的分隔符

  * 回车：执行键入的命令

  * `<>|`   ：重定向和管道
  
  * ; ，用于一行内输入多个命令
  
  * &，后台运行
  
  * $，引用shell变量
  
  * `，反向单引号，用于命令替换
  
  * `*[]？`，用于文件通配符
  
  * " "，双引号，除$和`的特殊字符的特殊含义被取消
  
  *  '，单引号，对所括起来的任何字符，Shell不作特殊解释，字符串中不允许单引号出现
  
    ```shell 
    # 由于使用单引号，可以在命令中输入任意字符
    # 输入以xxxx结尾的进程，并杀死
    pids=`ps -e| awk '/'$1'$/{printf("%d\n",$1);}'`
    echo $pids
    kill $pids
    ```

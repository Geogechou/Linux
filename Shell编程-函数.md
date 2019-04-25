## 函数

1. 语法

   `name(){list;}`

2. 参数引用

   调用时函数名后附加上0到多个参数

   在函数内部以*$1,$2,...或者$*，$@*方式引用。

3. 返回值

   函数体内用内部命令return使函数有返回码，0表示成功，非0表示失败

4. 举个栗子

   安装程序给出几项配置，让用户输入来确定选择

```shell
# 定义一个函数，函数的功能是提示用户做出选择
get_attr(){

        while true
        do
        		echo $2 ":" $4
        # \c是不要换行，-e是可以使用一些\开始的转义符号
                echo -e "$2 [$3]:\c"
                # 从命令行输入读取一个参数
                read val
                if [ "$val" = "" ]
                then
                	val=$3;
                	brak 2
                fi	
                # 对读入的参数进行判断，是否在预定的几个参数中
                for i in $4
                do
                # 如果存在就，退出2重循环
                        [ "$val" = "$i" ] && break 2
                done
                # 提示错误信息
                echo -e "****Invalid choice\"$val\",must be in \"$4\""
        done
        # eval函数进行赋值，重给第一个参数赋值
        eval "$1=$val"
}

get_attr COLOR "color of the box" white\
        "red green pink white black"
echo "you select color is: " $COLOR

```
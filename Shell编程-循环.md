## while循环的语法
```shell
while [ condition expression ]
do 
    main process
done
```

## for循环的语法

语法1

```shell
for name in word1 word2
	do list
done
```

举个栗子

```shell
# shell中定义数组的方式
nums=(1 2 3 4 5)
# for循环遍历数组
for i in ${nums[@]}
do 
	echo $i
done
```



语法2

```shell
for name
	do list
done
# 相当于,读取的是命令行参数
for name in $1 $2 ...
	do list
done
```

## for中使用seq(类似C中的for实现)

seq是产生一个整数序列

例如写成<code>a=`seq 1 20`; echo $a</code>

会输出*1 2 3 ......20*，20个数

```shell
for i in `seq 1 254`
do 
	ping -c 1 www.baidu.com
done
```

### break语句

例如`break`，退出循环

*break2*,退出两层循环

### continue语句

提交结束本轮循环

### exit语句

`exit 1`,退出并返回1
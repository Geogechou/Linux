## while循环的语法
```shell
while [ condition expression ]
do 
    main process
done
```

#### while循环实例

```shell
# 一共执行4次
i=0
while ((i<4))
do
((i+=1))
done
```

## for循环的语法

语法1

```shell
for name in word1 word2
do 
	main process
done
```

举个栗子

```shell
# shell中定义数组的方式
nums=(1 2 3 4 5)
# for循环遍历数组
for i in ${nums[@]}
do 
	# 依次输出 1 2 3 4 5 
	echo $i
done
```

例子2

```shell
# $1 $2是命令行参数
for name in $1 $2
do
	# 输出命令行第一个参数，第二个参数
	echo $name
done
```

### for中使用seq，类似python中的range(1,20)

seq是产生一个整数序列

```shell
# seq 1 20 会产生 1,2,3,...19,20个数
for i in `seq 1 20`
do 
	# 依次输出 1 2 3 ... 20
	echo $i
done
```

### break语句

例如`break`，退出循环

*break2*,退出两层循环

### continue语句

提交结束本轮循环

### exit语句

`exit 1`,退出并返回1
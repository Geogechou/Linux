* <a href="#id0">cat(concatenate and dissplay files)</a>
* <a href="#id1">more</a>
* <a href="#id2">head</a>
* <a href="#id3">tail</a>
* <a href="#id4">od</a>
* <a href="#id5">tee三通(在屏幕显示并且保存到文件中)</a>
* <a href="#id6">wc统计行数</a>
* <a href="#id7">tr替换字符</a>
## 文件类命令

<h3 id="id0">cat(concatenate and dissplay files)</h3>功能：将文件打印在屏幕上
选项
* -E 在每一行末尾显示$ 
* -n 显示时带上行号，来标注是第几行 

例子
```shell
#  在屏幕上显示文件m1
cat m1
# 创建一个文件，将输出结果匆匆屏幕中保存到filename中，Cltr+D结束   
cat>filename
# 在一个文件后追加内容  
cat>>filename
```

<h3 id="id1">more</h3>功能:显示一部分内容
操作：

* 空格，显示下一页 
* Enter,显示下一行 
* q,退出  

<h3 id="id2">head</h3>head命令显示一个文件的头部信息，默认10行 
`head -5 filename`,显示文件的前5行  

<h3 id="id3">tail</h3>显示文件的尾部信息，默认10行
参数  

*  -n:显示后n行 
* +n：从第n行显示到文件尾 

<h3 id="id4">od</h3>
 以八进制和十六进制显示文件内容

例子
```shell
# 以十六进制打印text.txt文件(x1表示十六进制，d1表示十进制)
od -t x1 text.txt
# 以字符形式打印text.txt文件
od -c text.txt
```

<h3 id="id5">tee三通(在屏幕显示并且保存到文件中)</h3>

```shell
# 将pointer.c的内容显示在屏幕上，同时输入到test文件中
cat pointer.c | tee test
```

<h3 id="id6">wc统计行数</h3>

```shell
# 统计所有c文件的行数
wc -l *.c
# 统计所有单词数
wc -w list.txt
# 统计字符数
wc -c list.txt
```

<h3 id="id7">tr替换字符</h3>

```shell
# 将所有小写字母替换成大写字母
cat report.txt | tr '[a-z]' '[A-Z]'
```

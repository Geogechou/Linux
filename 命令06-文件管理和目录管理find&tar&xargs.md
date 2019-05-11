## 文件管理和目录管理
* <a href="#find">find</a>
* <a href="#xargs">xargs</a>
* <a href="#tar">tar</a>
* <a href="#ls">ls</a>
* <a href="#cp">cp</a>
* <a href="#cd">cd</a>
* <a href="#mkdir">mkdir</a>
* <a href="touch">touch</a>
<h2 id="find">find</h2>

find命令来遍历目录树
 * **筛选选项**

   * `-name`选项

   ```shell
   # 在C1目录下找与名字'*.c'匹配的文件，并打印出来路径名，文件名的通配符要加上单引号，这里的文件名仅指路径的最后一部分
   find C1 -name '*.c' -print
   ```

   * `-regex pattern`

      pattern是整个路径名构成一个字符串

   * `-type`选项

     文件的属性字段可用来对遍历到的目标文件进行筛选, f：普通文件，d：目录...

     ```shell
     #  从当前目录开始查找，寻找所有目录，打印路径名
     find . -type d -print
     ```

   * `-mtime`选项

       ```shell
       # 从根目录开始检索最近10天之内曾经修改过的普通文件
       find / -type f -mtime -10 -print
       ```

  * **find关于动作的选项**

    -print，打印查找的文件的路径名

    -exec，对查找的目标执行某一命令

    ```shell
    #  对匹配到的文件名进行`ls -l`操作，**{}**代表遍历时查到符合条件的路径名，注意花括号后的空格不可或缺。-exec选项要和";"配对，find命令可以有好几个exec动作
    find /lib -name 'libc*.so' -exec ls -l {} \; 
    ```

    -ok，与-exec类似，只是对查找到符合条件的目标执行一个命令前需要操作员的确认

<h2 id="xargs">xargs</h2>

xargs是把标准输入追加到它的参数列表中，xargs可以与find配合使用，相当于执行-exec

```shell
# 找出所有c文件并通过管道，将打印出来的内容追加到grep命令后面作为(文件)参数
find C -name '*.c' -print | xargs grep -n 'include'
# xargs配合其他命令使用
# 打印当前所有文件和文件夹下的文件
ls | xargs ls
```

<h2 id="tar">tar</h2>

* -c：Create创建新磁带，从头开始写，以前存入磁带的数据会被覆盖掉

  -t：table列表，磁带上的文件名列表，当不指定文件名时，将列出所有的文件

* -x：extract抽取，从磁带中抽取指定的文件，当不指定文件名时，抽取所有文件

* -v：Verbose冗长，每处理一个文件，就打印出文件的文件名，并在该名前冠以功能字母

* -f：file，指定设备名称

* -z：采用gzip压缩

* -j：采用bzip2压缩

  ```shell
  # 将当前目录中的所有文件压缩到/home/george/Public/tar1中
  tar cvf /home/george/Public/tar1 .
  # 查看/home/george/Public/tar1的文件目录
  tar tvf /home/george/Public/tar1
  # 把/home/george/Public/tar1文件恢复到当前目录中
  tar xvf /home/george/Public/tar1
  # 将当前目录打包压缩为container.tar.gz（使用zip算法）
  tar cvzf container.tar.gz .
  
  ```

## gzip

`gzip txt`,将txt压缩为txt.gz

## gunzip

恢复压缩文件，`gunzip txt.gz`

 <h2 id="ls">ls</h2>

`ls -F`

若列出的是目录，则在名字后缀以斜线/

若列出的是可执行文件，就在名字后面缀以星号*

若是符号连接文件，则名字后无任何标记

`ls -l`格式解析

![](https://github.com/georgezhou314/imageRepo/raw/master/linux/lin3.png)

第二列，如图所示的是1，表示文件的link数。涉及到此文件的目录项数

第三列，第四列：文件主的名字和组号

第五列，文件的大小，单位(字节数), 如果是目录，则列出的是目录表的大小。

第六列，列出文件最后一次被修改的日期和时间

`ls -h`, 选项-h，以便于人阅读的方式打印数值，例如(1K,234M)

`ls -a`, 列出文件名首字符为圆点的文件

<h2 id="cp">cp命令</h2>

拷贝文件到当前目录

`cp temp/*.so .`   ,  **.**表示当前目录

选项-r，递归复制，用于复制目录

选项-u，增量拷贝，用于备份目录，根据文件的时间戳，不拷贝相同的或者过时的文件

<h2 id="rm">rm</h2>

选项-r, 递归删除

选项-i，每删除一个文件前需要操作员确认

选项-f，强制删除，可以删除只读文件

<h2 id="cd">cd</h2>

cd后无参数，则返回用户的主目录(Home directory)

<h2 id="mkdir">mkdir</h2>

选项-p，自动创建路径中不存在的目录

`mkdir sun/work/studio -p`, 如果不指明-p，不会创建多级目录

<h2 id="touch">touch</h2>

将文件的最后一次修改时间改为当前时间，不改变文件内容

`touch book.txt`
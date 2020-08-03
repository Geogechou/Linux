* <a href="#id0">ls命令(list)</a>
* <a href="#id1">pwd(print working directory)</a>
* <a href="#id2">cp(copy)</a>
* <a href="#id3">rm(remove)</a>
* <a href="#id4">mv命令</a>
* <a href="#id5">cd(change directory)</a>
* <a href="#id6">mkdir(make directory)</a>
* <a href="#id7">rmdir(remove directory)</a>
## 文件类命令

<h3 id="id0">ls命令(list)</h3>
```shell
# 查看filename文件的详细信息
ls -l filename
# 显示所有文件，包括隐藏文件
ls -a
# 以修改时间排序
ls -t

```
<h3 id="id1">pwd(print working directory)</h3>显示当前所在的工作目录
`pwd`

<h3 id="id2">cp(copy)</h3>语法： cp [参数] <源文件路径><目标文件路径> 
参数：
 * -p连同文件的属性一起复制，常用于备份
*  -i 若目标文件已经存在，在覆盖前会先询问操作的进行
* -r 递归持续复制，用于目录的复制行为
* -u目标文件与源文件有差异才会复制

<h3 id="id3">rm(remove)</h3>删除文件或目录 
格式 rm [参数] <目标文件路径> 
参数 
* -f force,忽略不存在的文件，不会出现警告消息
* -i互动模式，删除前会询问
* -r递归删除，用于目录的删除

<h3 id="id4">mv命令</h3>
例子：

* `mv file1 file1_ch`

  重命名file1为file1_ch

<h3 id="id5">cd(change directory)</h3>
*每个目录下有两个特殊的目录`.`(同级目录)和`..`(上级目录)*

语法: `cd [目录]  `

例子：
```shell
 #切换到根目录 
cd /
# 回到上一级目录  
cd  ..
# 返回home目录
cd ~
# 返回上一次工作目录
cd -
```

<h3 id="id6">mkdir(make directory)</h3>语法: mkdir [目录名] 
例子：

```shell
#创建新目录  
mkdir newdir
```

<h3 id="id7">rmdir(remove directory)</h3>删除空目录 


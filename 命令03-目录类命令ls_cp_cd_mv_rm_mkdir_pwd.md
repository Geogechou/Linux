## 文件类命令

### ls命令(list)
```shell
# 查看filename文件的详细信息
ls -l filename
# 显示所有文件，包括隐藏文件
ls -a

```
### pwd(print working directory)
显示当前所在的工作目录
`pwd`

### cp(copy)
语法： cp [参数] <源文件路径><目标文件路径> 
参数：
 * -p连同文件的属性一起复制，常用于备份
*  -i 若目标文件已经存在，在覆盖前会先询问操作的进行
* -r 递归持续复制，用于目录的复制行为
* -u目标文件与源文件有差异才会复制

### rm(remove)
删除文件或目录 
格式 rm [参数] <目标文件路径> 
参数 
* -f force,忽略不存在的文件，不会出现警告消息
* -i互动模式，删除前会询问
* -r递归删除，用于目录的删除

### mv命令

例子：

* `mv file1 file1_ch`

  重命名file1为file1_ch

### cd(change directory)

*每个目录下有两个特殊的目录`.`(同级目录)和`..`(上级目录)*

语法: `cd [目录]  `

例子：
```shell
 #切换到根目录 
cd /
# 回到上一级目录  
cd  ..
```

### mkdir(make directory)  
语法: mkdir [目录名] 
例子：

```shell
#创建新目录  
mkdir newdir
```

### rmdir(remove directory)
删除空目录 


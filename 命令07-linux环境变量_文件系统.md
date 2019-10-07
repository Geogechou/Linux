<a href="#env">环境变量</a>

<a href="#xsel">复制文件中的文本xsel</a>

<a href="#fileSystem">文件系统</a>

* <a href="#symbollink">符号链接</a>

## linux系统环境变量

* 配置文件

* 环境变量

  命令`env`，打印出环境变量

  * LANG(语言选择)

  * HOME(主目录)

  * TERM(终端类型)

  * PATH(可执行文件的查找路径)

  * CLASSPATH(类库查找路径)

  在运行程序时指定临时环境变量`$ JAVA_HOME=/home/george/java ./env.c `

  导出环境变量:`export JAVA_HOME=/home/george/jdk/`

* 命令行参数

* 交互式键盘输入

<h3 id="xsel">xsel命令</h3>
需要安装xsel

`cat env.c | xsel`, 将env.c的内容复制到剪贴板上。

<h2 id="fileSystem">文件系统</h3>

* 根文件系统

* 子文件系统，以跟文件系统中的某一子目录的身份出现

  #### mount，查看文件系统(文件系统创建)

  `mount | grep ext` 查看文件系统

  #### df : 报告磁盘使用情况

  `df -h`，h是human-readable，便于人阅读的格式输出


 <h3 id="symbollink"> 符号链接</h3>
`ln -s books sym.link`, 建立books文件的符号链接sym.link文件，符号链接文件的文件类型是l。

符号链接文件仅仅保存被链接文件的文件名。

若符号链接包含绝对路径名，引用绝对路径名。

若符号链接包含相对路径名，是相对于符号链接文件的位置(不是相对于调用进程的当前工作目录)。

`ls -i `， 打印文件的inode信息

![符号链接数据结构](https://raw.githubusercontent.com/georgezhou314/imageRepo/master/linux/文件2.png)

### 系统调用

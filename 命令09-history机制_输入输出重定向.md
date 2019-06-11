### Shell的基本机制

shell是面向命令处理的语言

* <a href="#history">history机制</a>
* <a href="#alias">alias</a>
* <a href='#inputRedirect'>输入重定向</a>
* <a href="#output">输出重定向</a>
### 1. 启动bash

三种启动方法

* 注册shell
* 交互式shell
* 脚本解释器

#### 用户级启动bash

当bash作为注册shell被启动时，自动执~/.profile

当bash作为注册shell退出时，执行~/.bash_logout

当bash作为交互式shell启动时，自动执行~/.bashrc

#### 系统级启动bash

当bash作为注册shell被启动时，自动启动/etc/profile

当bash作为交互式shell被启动时，自动执行/etc/bash.bashrc

当bash作为注册shell被退出时，自动启动/etc/bash.bash.layout

#### 脚本文件的执行

* 新建一个子进程执行

  `bash<lsdir.sh`, 该方式无法携带命令行参数

  `bash -x lsdir.sh`，-x选项每执行一行命令，先把这行命令内容打印出来

  `./lsdir.sh`，将lsdir.sh文件修改为可执行的

* 在当前shell进程中执行脚本

  `. lsdir.sh`,  .(dot)与source作用相同

  `source lsdir.sh`

  在当前shell执行，会影响当前的状态

<h3 id="history">2. 历史机制</h3>

### history

打印历史执行过的命令

### !!

引用上一条命令

### !str

以str开头的最近用过的命令

`!ja`, 执行最近执行过的`java -version`命令

<h3 id="alias">3.命令取别名</h3>

`alias p="ping www.baidu.com -c 3"`

只要输入`p`,就完成了网络测试了

如果需要，可以把alias命令放入~/.bashrc中

<h3 id="inputRedirect">4. 输入重定向</h3>

脚本文件inputRedirect.sh

```shell
read -p "enter a num" s0
echo 's0 is ' $s0
```

运行该脚本，正常运行

`./inputRedirect.sh`

会在标准输入中等待输入，并给出提示符"enter a num"

#### 1. 文件输入重定向

`./inputRedirect.sh<info`，从文件info中获取stdin

#### 2. <<word (从shell中获得stdin)

从shell脚本文件中获取数据，直到再次遇到定界符word

```shell
# 完成了终端输入
mysql -uroot -p123456<<EOF
use example;
select * from table1;
EOF
# 脚本文件中的`date`（``）之间的内容作为命令执行结果
cat<<EOF
`cal`
EOF
会把日历打印出来，而不是cal字符串
```

#### 3.<<<word

将后面的输入作为命令的读取

```shell
base64<<<123
# 将123作为base64的输入
# base64是一种编码方式
```

<h3 id="output">5.输入重定向</h3>

#### 1. >filename

将标准输出重定向到文件filename中，文件已存在则清空(覆盖)

#### 2.>>filename

将标准输出重定向追加到文件filename尾

#### 3. 管道

管道默认仅重定向标准输出，不重定向标准错误输出

`gcc try.c 2>&1 | more`，将标准错误输出和标准输出同时定向到more中
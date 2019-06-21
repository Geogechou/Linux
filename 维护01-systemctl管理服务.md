* <a href="#id0">systemctl管理服务</a>
* <a href="#id1">删除服务</a>
* <a href="#id2">Tomcat自启动服务设置</a>
<h3 id="id0">systemctl管理服务</h3>
`systemctl start mysql`

开启mysql服务

`systemctl status mysql`

查看mysql服务

`systemctl stop mysql`

关闭mysql服务

<h3 id="id1">删除服务</h3>
`update-rc.d -f my_service remove`

使用update-rc.d删除服务之后，sysv-rc-conf的列表中仍然存在。此时可以手动编辑`/var/lib/sysv-rc-conf/services`文件进行删除

<h3 id="id2">Tomcat自启动服务设置</h3>
修改**/etc/rc.local**

```shell

#!/bin/bash -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.
export JAVA_HOME=/usr/local/jdk-11.0.2
export PATH=$JAVA_HOME/bin:$PATH
export CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar
export CATALINA_HOME=/home/pan/tomcat
export CATALINA_BASE=/home/pan/tomcat
MYSQL_HOME=/usr/local/mysql
PATH=$MYSQL_HOME/bin:$PATH
export PATH MYSQL_HOME
# 自动启动mysql和tomcat
# 需要手动导入环境变量
# 可能与/etc/profile和该文件加载前后有关
systemctl start mysql
bash /home/pan/tomcat/bin/startup.sh
exit 0
```

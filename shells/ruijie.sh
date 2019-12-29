# 脚本功能:
# 启动锐捷服务 与 重启锐捷服务
#
#
#
# 选项是--help或者-help
if [ "$1" = "-help" -o "$1" = "--help" ]; then
				echo "-r restart"
elif [ "$1" = "-r" ] ; then
				echo "重启网络连接"
				sudo pkill -f mentohust
				#d1表示动态分配dhcp v后面是版本号
				sudo mentohust -u201xxxxx -pxxxxx -d1 -v6.82 &
# 选项是空字符串的情况
elif [ -z "$1" ]; then
	echo "启动网络连接"
	sudo mentohust -u201xxxx -pxxx -d1 -v6.82 &
else
				echo "未定义选项"
fi

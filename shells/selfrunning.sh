# run plank,要在后台运行,否则进入桌面失败
pid=`pidof plank`
# 如果没有该进程,就运行
if [ -z  $pid ];then
	plank &
	echo "pid is None"
else
# 否则,先杀掉进程再启动
	sudo kill $pid
	plank &
	echo "pid is: "$pid
fi


# 用awk调用df命令统计磁盘总共的空间和剩余空间
df |awk '
{sum+=$2;free+=$4;}
END{	
	printf "磁盘总容量有："
	if(sum>(1024*1024))
	       	print  sum/(1024*1024),"GB"
	else
		print  sum/1024,"MB"
	printf "磁盘可用空间有："
	if(free>(1024*1024))
		print free/(1024*1024),"GB"
	else
		print free/1024,"MB"
}
'

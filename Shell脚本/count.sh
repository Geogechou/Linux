# while 逐行读一个文件
get_count(){
	echo "param:" $1
	temp=0;
cat books | while read line
do
	temp=`expr $temp + $line`
	echo "temp is $temp"
done
}
get_count SUM
echo "end" $SUM

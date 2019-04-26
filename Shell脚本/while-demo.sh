b=$1;
if [ $# = 0 ]
then echo "no pbrbm"
	exit -1;
fi
while [ $b -gt 0 ] 
do
	echo $b
	b=`expr $b - 1`
done
echo "end"

func(){
val=$1
val=`echo "$val + 100"|bc -l`
echo "val is: $val"
eval "$1=$val"
}

func num
echo "num is:$num"

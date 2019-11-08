get_attr(){

	while true
	do
		echo $2 ":" $4
		echo -e "your select is [$3]:\c"
		read val
		if [ "$val" = "" ]
		then
			val=$3;
			break 2
		fi
		for i in $4
		do
			[ "$val" = "$i" ] && break 2
		done
		echo -e "****Invalid choice\"$val\",must be in \"$4\""
	done
	eval "$1=$val"
}

get_attr COLOR "color of the box" "white"\
	"red green pink white black"
echo "you select" $COLOR

num=1
echo $num num
while [ $num -lt 20 ]
	do
		jpg=".jpg"
		temp=$num$jpg
		#echo $temp
        wget http://zhjw.scu.edu.cn/img/captcha.jpg -O $temp
		num=`expr $num + 1`
	done


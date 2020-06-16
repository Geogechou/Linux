#!/bin/bash
lastword=""
while :
do
	word=`xsel -o`
	echo $word
	if [ -n "$word" ] && [ "$word" != "$lastword" ];then
		url='https://cn.bing.com/dict/search?q='$word
		echo $url
		x-www-browser $url
	fi
	lastword=$word
	sleep 2
done

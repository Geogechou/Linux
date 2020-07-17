# copy file to hexo
# #@ 返回命令行参数列表,不包括$0
for param in $@
do
	echo $param
	cp $param /root/myhexo/source/_posts
done
# hexo generation
cd myhexo
hexo g


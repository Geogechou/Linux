pwd
echo Now redirect to /home/geoge/cpp_files to calculate how many file in there.
dir=/home/geoge/cpp_files
[ -d $dir ] &&{

	cd $dir
	echo "current directory is `pwd`"
	echo "`ls | wc -l` files"
}
pwd

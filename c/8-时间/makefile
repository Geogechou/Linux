#注释
#声明变量
PWD=pwd
#输入make之后执行的命令
all: mtime time

mtime:mtime.c
	gcc mtime.c -o mtime
	mkdir bin
	mv mtime bin
	#引用变量
	$(PWD)
time: time.c
	gcc time.c -o time
	mv time bin
#输入make clean之后执行的操作
clean:
	rm -rf time mtime
	rm -rf bin

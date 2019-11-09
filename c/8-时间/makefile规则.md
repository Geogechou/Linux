```makefile
PWD=pwd
all: mtime time

mtime:mtime.c
	gcc mtime.c -o mtime
	mkdir bin
	mv mtime bin
	$(PWD)
time: time.c
	gcc time.c -o time

clean:
	rm -rf time mtime
```
**all**
输入`make`命令自动执行，是所有要编译的文件
**mtime:mtime.c**
可执行文件的依赖
`gcc mtime.c -o mtime`编译命令,行开始前需要一个TAB
也可以写操作系统的命令，例如mtime下的新建一个bin目录，将可执行文件移动到bin中
**clean**
是一个标签，使用时输入`make clean`执行clean下的一条命令
**变量**
在all之前定义的PWD=pwd, 在makefile文件中可以用$(PWD)代替pwd




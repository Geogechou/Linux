### gdb调试

1. gcc编译选项`gcc hello.c -o -g hello`
2. gcc调试程序`gcc hello`
3. gdb列出程序代码,`list`
4. 调试设置main函数参数 `set args para1 para2`
5. 设置断点`b 11`,在11行设置断点
6. start,开始运行
7. 运行，一直运行到断点处,`run`
8. Step Into，`s`,有函数就进入,库函数无源代码是进不去的
9. Step Over,'n'，有函数就跳过
10. 运行剩余部分,直到遇到断点处停下来，`c`
11. 打印变量，`print(i)`,打印i的值,也可以简写 p ia
12. 设置变量名, `set k=v`
13. 退出，`q`

# makefile定义一个变量，cc表示gcc
CC = gcc
main: main.c max.o min.o
	$(CC) main.c max.o min.o -o main
max.o:max.c
	$(CC) -c max.c -o max.o
min.o:min.c
	$(CC) -c min.c -o min.o
clean:
	rm *.o main

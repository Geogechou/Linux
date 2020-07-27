CC = gcc
# 生成两个可执行文件，分别是main_max,main_min
all: main_max main_min

main_min: main_min.c max.o min.o
	$(CC) main_min.c max.o min.o -o main_min
main_max: main_max.c max.o min.o
	$(CC) main_max.c max.o min.o -o main_max
max.o:max.c
	$(CC) -c max.c -o max.o
min.o:min.c
	$(CC) -c min.c -o min.o
clean:
	rm *.o main_max main_min

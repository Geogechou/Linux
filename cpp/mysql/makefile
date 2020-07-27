include=`mysql_config --cflags`
libs=`mysql_config --libs`
all:curd

curd:curd.cpp
	g++ -o curd.out $(include) curd.cpp $(libs)
clean:
	# echo $(include) $(libs)
	rm curd.out
run:
	./curd.out

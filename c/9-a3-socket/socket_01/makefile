all: tcpserver.out tcpclient.out
%.out: %.c
	gcc $^ -o $@
clean:
	-rm *.out
client:	tcpclient.out
	./tcpclient.out
server: tcpserver.out
	./tcpserver.out

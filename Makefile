all:client server
client:client.o error.o sqlite3.o
	gcc client.o error.o sqlite3.o -o client -lsqlite3 -lpthread
server:sqlite3.o server.o error.o
	gcc sqlite3.o server.o error.o -o server -lsqlite3 -lpthread

sqlite3.o:sqlite3.c
	gcc -c sqlite3.c
server.o:server.c
	gcc -c server.c
client.o:client.c
	gcc -c client.c
error.o:error.c
	gcc -c error.c	


.PHONY:clean
clean:
	rm -f *.o
	rm -f server
	rm -f client
	rm -f *.db

 
clear:
	rm *.db

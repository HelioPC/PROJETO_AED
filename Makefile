CFLAGS = -g -c -std=c18 -Wall -Wpedantic -Wextra

all: main
	rm -f *.o

main: main.o aberturadeconta.o auxiliar.o cliente.o data.o essentials.o histórico.o kid.o lscli.o lshst.o lskid.o menus.o messages.o
	gcc -o main main.o aberturadeconta.o auxiliar.o cliente.o data.o essentials.o histórico.o kid.o lscli.o lshst.o lskid.o menus.o messages.o

main.o: main.c
	gcc $(CFLAGS) main.c

aberturadeconta.o: aberturadeconta.c
	gcc $(CFLAGS) aberturadeconta.c

auxiliar.o: auxiliar.c
	gcc $(CFLAGS) auxiliar.c

cliente.o: cliente.c
	gcc $(CFLAGS) cliente.c

data.o: data.c
	gcc $(CFLAGS) data.c

essentials.o: essentials.c
	gcc $(CFLAGS) essentials.c

histórico.o: histórico.c
	gcc $(CFLAGS) histórico.c

kid.o: kid.c
	gcc $(CFLAGS) kid.c

lscli.o: lscli.c
	gcc $(CFLAGS) lscli.c

lshst.o: lshst.c
	gcc $(CFLAGS) lshst.c

lskid.o: lskid.c
	gcc $(CFLAGS) lskid.c

menus.o: menus.c
	gcc $(CFLAGS) menus.c

messages.o: messages.c
	gcc $(CFLAGS) messages.c

clean:
	rm -f *.o main
CC = gcc
CC-flags = -Wall


all: prog03 minMax

prog03: prog03.o
	$(CC) prog03.o -o res3 $(CC-flags)

prog03.o: prog03.c
	$(CC) -c prog03.c $(CC-flags)

minMax: minMax.o
	$(CC) minMax.o -o minMax $(CC-flags)

minMax.o: minMax.c
	$(CC) -c minMax.c $(CC-flags)

clean:
	-rm -f prog03.o
	-rm -f prog03
	-rm -f res3
	-rm -f minMax.o
	-rm -f minMax
	

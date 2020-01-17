intrep: main.c read_integers.o messages.o
	gcc -o intrep read_integers.o messages.o main.c 

read_integers.o: read_integers.c read_integers.h
	gcc -c read_integers.c

messages.o: messages.c messages.h
	gcc -c messages.c 

clean:
	rm -rf *.o intrep
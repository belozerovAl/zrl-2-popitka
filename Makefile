.PHONY: clean, run, all

all: hello

run: hello
	./hello
main.o: main.c
	gcc -c main.c
bin.o: bin.c
	gcc -c bin.c
oct.o: oct.c
	gcc -c oct.c
hex.o: hex.c
	gcc -c hex.c
hello: main.o bin.o oct.o hex.o
	gcc main.o bin.o oct.o hex.o -lm -o hello 
clean: 
	rm -rf *.o hello


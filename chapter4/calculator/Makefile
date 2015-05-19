CC=gcc
CFLAGS=-I -lm.
DEPS = calc.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calcmake: getch.o getop.o main.o stack.o
	$(CC) -lm -o calculator.out getch.o getop.o main.o stack.o


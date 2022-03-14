CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`

all: sdltest

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LIBS)

sdltest: main.o
	$(CC) $(CFLAGS) -o sdltest main.o $(LIBS)

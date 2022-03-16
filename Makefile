CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer`
LIBS=`pkg-config --libs sdl2` `pkg-config --libs SDL2_mixer`

all: sdltest

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LIBS)

sdltest: main.o
	$(CC) $(CFLAGS) -o sdltest main.o $(LIBS)

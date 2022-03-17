PKGS=sdl2 SDL2_mixer
CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb `pkg-config --cflags $(PKGS)`
LIBS=`pkg-config --libs $(PKGS)`

all: sdltest

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LIBS)

sdltest: main.o
	$(CC) $(CFLAGS) -o sdltest main.o $(LIBS)

CC=gcc
CFLAGS=-Wall -g
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs) -lm

all: kml.o lab11

kml.o: kml.c kml.h
	$(CC) $(CFLAGS) -c kml.c

lab11: lab11.c kml.o
	$(CC) $(CFLAGS) $(SDL_CFLAGS) lab11.c kml.o -o lab11 $(SDL_LDFLAGS)

clean:
	rm kml kml.o

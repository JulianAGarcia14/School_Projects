CC=gcc
CFLAGS=-Wall -g
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs) -lm

all: permutation

permutation: permutation.c randint.h
	$(CC) $(CFLAGS) $(SDL_CFLAGS) permutation.c -o permutation $(SDL_LDFLAGS)

russian: russian.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) russian.c -o russian $(SDL_LDFLAGS)

clean:

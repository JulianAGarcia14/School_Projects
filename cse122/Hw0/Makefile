CC=gcc
CFLAGS=-Wall -g
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs) -lm

all: fizzbuzz sum sum_no_for newton_sqrt newton_cube cube_binary

fizzbuzz: fizzbuzz.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) fizzbuzz.c -o fizzbuzz $(SDL_LDFLAGS)

sum: sum.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) sum.c -o sum $(SDL_LDFLAGS)

sum_no_for: sum_no_for.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) sum_no_for.c -o sum_no_for $(SDL_LDFLAGS)

newton_sqrt: newton_sqrt.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) newton_sqrt.c -o newton_sqrt $(SDL_LDFLAGS)

newton_cube: newton_cube.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) newton_cube.c -o newton_cube $(SDL_LDFLAGS)

cube_binary: cube_binary.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) cube_binary.c -o cube_binary $(SDL_LDFLAGS)

clean:

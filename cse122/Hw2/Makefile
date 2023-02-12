CC=gcc
CFLAGS=-Wall -g
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs) -lm

all: fib_error fib foo foo10

fib_error: fib_error.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) fib_error.c -o fib_error $(SDL_LDFLAGS)

fib: fib.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) fib.c -o fib $(SDL_LDFLAGS)

foo: foo.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) foo.c -o foo $(SDL_LDFLAGS)

foo10: foo10.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) foo10.c -o foo10 $(SDL_LDFLAGS)

clean:

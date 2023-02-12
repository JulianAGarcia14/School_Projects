CC=gcc
CFLAGS=-g -Wall
targets = sum sqrt
all: $(targets)

# $@ is the name of the target

%: %.c
	$(CC) $(CFLAGS) $@.c -o $@

.PHONY: .clean
clean:
	rm -rf $(targets)

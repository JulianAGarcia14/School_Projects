CC=gcc
CFLAGS=-g -Wall

targets = test_qsort heapsort test_heap repeated scrabble_bsearch
all: $(targets)

heapsort: heapsort.c
	$(CC) $(CFLAGS) -c $@.c

test_heap: test_heap.c heapsort
	$(CC) $(CFLAGS) $@.c heapsort.o -o $@

repeated: repeated.c
	$(CC) $(CFLAGS) $@.c -o $@

scrabble_bsearch: scrabble_bsearch.c
	$(CC) $(CFLAGS) $@.c -o $@

test_qsort: test_qsort.c
	$(CC) $(CFLAGS) $@.c -o $@

.PHONY: clean
clean:
	rm -rf *.o $(targets)

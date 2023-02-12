CC=gcc
CFLAGS=-g -Wall

all: fizzbuzz f2c palindrome array_structures linked_list

fizzbuzz: fizzbuzz.c
	$(CC) $(CFLAGS) fizzbuzz.c -o fizzbuzz

f2c: f2c.c
	$(CC) $(CFLAGS) f2c.c -o f2c 

palindrome: palindrome.c
	$(CC) $(CFLAGS) palindrome.c -o palindrome

array_structures: array_structures.c
	$(CC) $(CFLAGS) array_structures.c -o array_structures

linked_list: linked_list.c
	$(CC) $(CFLAGS) linked_list.c -o linked_list

clean:
	rm fizzbuzz f2c palindrome array_structures linked_list

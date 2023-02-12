CC=gcc
CFLAGS=-g -Wall
CFLAGS_OBJ=-g -Wall -c
AVL_OBJ=avl.o
BST_OBJ=bst.o

all: avl avl_test bst bst_test test

avl: avl.c avl.h
	$(CC) $(CFLAGS_OBJ) avl.c

avl_test: avl_test.c avl
	$(CC) $(CFLAGS) avl_test.c $(AVL_OBJ) -o avl_test

test: test.c avl
	$(CC) $(CFLAGS) test.c $(AVL_OBJ) -o test

bst: bst.c bst.h
	$(CC) $(CFLAGS_OBJ) bst.c

bst_test: bst_test.c bst
	$(CC) $(CFLAGS) bst_test.c $(BST_OBJ) -o bst_test

clean:
	rm *.o avl_test bst_test

CC=gcc
CFLAGS=-g -Wall

targets=lex postfix stack words unique_words
all: $(targets)

lex: lex.c lex.h
	$(CC) $(CFLAGS) -c $@.c

postfix: postfix.c lex
	$(CC) $(CFLAGS) $@.c lex.o -o $@

stack: stack.c stack.h
	$(CC) $(CFLAGS) -c $@.c

test_stack: test_stack.c stack
	$(CC) $(CFLAGS) $@.c stack.o -o $@

words: words.c
	$(CC) $(CFLAGS) $@.c lex_word.o -o $@

unique_words: unique_words.c
	$(CC) $(CFLAGS) $@.c lex_word.o -o $@

#don't remove lex_word.o when cleaning
clean:
	rm -rf lex.o stack.o $(targets)

/**
 * @file test_heap.c
 *
 * @author Julian Garcia
 *
 * @date 4/14/2019
 *
 * Assignment: Homework 6
 *
 * @brief  Program which sorts, and cleans input text
 *
 * @details Uses a doubling realloc scheme to allocate strings from input text into an array
 *	    which is then turned to all lowercase and sorted.
 *
 * @bugs
 *
 * @todo
 */


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "heapsort.h"

#define LEN 4096
enum {INIT = 1, GROW = 2};


/** convert string to lowercase
 * @param s string to be lowercased
 * @return void
 */
void tolowercase(char *s)
{

        while (*s != '\0') {
            if (*s >= 'A' && *s <= 'Z') {
                *s = *s + 32;
            }
            ++s;
        }

}

/** trim off whitespace from the right
 * see the manpage for isspace
 * @param s string to be de-spaced
 * @return void
 */
void rstrip(char *s)
{
	int i = 0;
	int index;
	while(*s != '\0') {
		if(*s == '\n') {
			*s = '\0';
		}
		if (*s != ' ') {
			index = i;
		}
	i++;
	s++;
	}
	s[index + 1] = '\0';

}


/** Compares two  values
 * @param a, b values to be compared
 * @return A value given by strcmp representing whether the strings are equal
 */
int comp (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[])
{
        char buf[LEN];
	char *t = NULL;

	char **list = NULL;
	int word = INIT;
	int i;
	FILE *fp;
	int max = INIT;

	fp = fopen(argv[1], "r");
	assert(fp);

	while(fgets(buf, LEN, fp)) {
		/* remove new line */
		rstrip(buf);
		tolowercase(buf);

		t = malloc((strlen(buf) + 1) * sizeof(char));

		strncpy(t, buf, strlen(buf) + 1);

		if(list == NULL) {
			list = malloc(sizeof(char *));
		} else if (word > max) {
			list = realloc(list, GROW * max * sizeof(char *));
			max = GROW * max;
		}

		list[word - 1] = t;
		word++;
	}
        /* overcounted */
        word--;

        /* print the list */
	for(i = 0; i < word; i++){
		printf("%s\n", list[i]);
	}

        printf("\n");

	/* todo sort list with heapsort */
        /* user needs to provide comparison function */
	char *temp;

	for (i = (word); i >=0 ; i--){

		heapsort(list, word, sizeof(list[i]), comp, i);
	}

	for (i = (word); i >=0 ; i--){

		temp = list[0];
		list[0] = list[i];
		list[i] = temp;
		heapsort(list, i, sizeof(list[i]), comp, 0);
	}

        /* print the sorted list */
        for(i = 0; i < word; i++) {
		printf("%s\n", list[i]);
	}

	fclose(fp);
	free(t);
	free(list);

       return 0;
}

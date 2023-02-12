/**
 * @file repeated.c
 *
 * @author Julian Garcia
 *
 * @date 4/14/2019
 *
 * Assignment: Homework 6
 *
 * @brief Program which searches for first repeated character of inputted string
 *
 * @details Uses an int array to index which characters have occured by their ascii values.
 *
 * @bugs
 *
 * @todo
 */

#include <stdio.h>
#include <stdlib.h>

char strchrrep(char *s, int a[]);
void rstrip(char *s);
void tolowercase(char *s);

int main(int argc, char **argv)
{

	if (argc != 2) {
		printf("error in input\n");
		printf("usage: ./repeated [STRING]\n");
		printf("where [STRING] is the string to find the first repeated character in\n");
		exit(EXIT_FAILURE);
	}

	int a[128];
	rstrip(argv[1]);
	tolowercase(argv[1]);
        char d = strchrrep(argv[1], a);
	if(d == 0) {
		printf("No repeated characters\n");
		return 0;
	}

	/* print the first repeated char in argv[1] */
	printf("First repeated character is %c\n", d);

	return 0;
}

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

/** Searches for first repeated character of a string
 * @param s string to be evaluated
 * @return first repeated character
 */
char strchrrep(char *s, int a[])
{
	char c;
	int i = 0;
	int b;
	while(s[i] != '\0') {
		c = s[i];
		b = c - '0';
		a[b]++; /*Subtract one because int array begins at 0*/

		if(a[b] == 2) {
			return c;
		}
		i++;
	}
	return 0;
}

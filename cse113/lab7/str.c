/**
 * @file str.c
 *
 * @author Julian Garcia
 *
 * @date 11/4/2018
 *
 * Assignment: Lab 7
 *
 * @brief Written string functions
 *
 * @details Functions for test.c which involves concatenating, copying, and indexing strings, among other functions.
 *
 * @bugs
 *
 * @todo none
 */


#include "str.h"
#include <stdio.h>
#include <string.h>


/** Determines if an element is in the string
 * @param *s is the given string
 * @param c is the desired element
 * @return null if not found, address if found
 */
char *pindex(char *s, int c)
{

	while (*(s)++ != '\0') {

		if (*s == c) {
			return s;
		}


	}

	return NULL;


}

/** Determines if strings are of same length
 * @param *s is a given string
 * @param *t is another string
 * @return 0
 */
int pstr_ncmp(char *s, char *t, int n)
{
	for (; n--; t++, s++) {

		if (*s != *t) {
			return *s - *t;
		}
	}
	return 0;
}


/** finds the length of the string
 * @param *s is the given string
 * @return length of string
 */
int str_len(char *s)
{

	int i = 0;

	while ( *(s + i) != '\0') {
		i++;
	}

        return i;
}

/* array version */
/* concantenate t to the end of s; s must be big enough */
void str_cat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') 	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

/* array version */
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}

/** Removes a certain element from the string
 * @param *s is the given string
 * @param c is the desired element
 * @return void
 */
void psqueeze(char *s, int c)
{

	int j = 0;
	int i  = 0;


	while ( *(s + i) != '\0') {
		i++;
		if (*(s + i) != c) {
			*(s + j++) = *(s + i);

		}
	}


	*(s + j) = '\0';


}

/** Swaps characters
 * @param *s is the given character
 * @param *s is the element to be swapped with
 */
void cswap(char *c, char *d)
{

	int b;

	b = *c;
	*c = *d;
	*d = b;

}

/** Reverses order of string
 * @param *s is the given string
 * @return void
 */
void preverse(char *s)
{
	int i, j;

	for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		*/
		cswap((s + i), (s + j));
	}

}


/** Copy n chars of src into dest
 * @param *dest is the destination of the copied characters
 * @param *src is the source of the characters to be copied
 * @param n is the number of characters to be copied
 * @return void
 */
void pstr_ncpy(char *dest, char *src, int n)
{

//	strncpy(dest, src, n);

	size_t i;

        	for (i = 0; i < n && src[i] != '\0'; i++)
                	*(dest + i) = *(src + i);
                for ( ; i < n; i++)
                   	*dest = '\0';




}

/* concantenate t to the end of s; s must be big enough! */
/** Concantenates t to end of s
 * @param *s is the given string
 * @param *t is the string to be concantenated
 * @return void
 */
void pstr_cat(char *s, char *t)
{
	int i, j;

	i = j = 0;
	while (*(s + i) != '\0')	/* find end of s */
		i++;
	while ((*(s + i++) = *(t + j++)) != '\0') /* copy t */
	;

}

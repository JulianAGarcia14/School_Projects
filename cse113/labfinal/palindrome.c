#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	for (i = 0, j = strlen(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		*/
		cswap((s + i), (s + j));
	}

}


/* Returns 1 if it is a palindrome, 0 if it isn't */
int palindrome (char *string) {

	//your code goes here
	char *s;
	size_t len = strlen(string) + 1; /* 1 for the NULL char */
	s = malloc(len * sizeof(char));
	strncpy(s, string, strlen(string) + 1);
	preverse(s);
	if(strcmp(s, string) == 0) {
		return 1;
	} else {
		return 0;
	}


	free(s);

	return 1;
}

int main() {
	char *strings [] = {"kayak", "duck", "moon", "ada", "racecar", "leveled", "stats", "statistics"};
	int i, check;
	for (i = 0; i < sizeof(strings) / sizeof(char *); i ++) {
		check = palindrome(strings[i]);
		if (check == 1)
			printf("%s is a palindrome.\n", strings[i]);
		else if (check == 0)
			printf("%s is not a palindrome.\n", strings[i]);
		else
			printf("Error in processing palindrome.\n");
	}

	return 0;
}

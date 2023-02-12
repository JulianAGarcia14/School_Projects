/* I found 6 bugs */

/*This should be <stdio.h>*/
#include <stdio>

/*This should be int main or return 0 should be removed*/
void main()
{
	char input;
	printf("Enter a character: \n");
	/* %c is used for char values, and getchar would be better here*/
	scanf("%f", input);
	switch (input) {

	case 'a':
		printf("A is for apple.\n");
		/*There should be a break; after this statement */

	/* There should be a colon instead of a semicolon after 'b'*/
	case 'b';
		/* /n should instead be \n here */
		printf("B is for Banana!/n");
		break;

	default:
		printf("The letter %d isn't important!\n", input);
	}
	return 0;
}

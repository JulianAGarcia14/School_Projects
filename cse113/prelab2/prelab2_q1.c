#include <stdio.h>

int main()
{
	/*Declares input*/
	int input = 0;
	/*asks for input*/
	printf("Enter an integer: \n");
	/*Receives input*/
	scanf("%d", &input);
	/*Prints messages depending on if the entered value was 1, 2, or any other value*/
	if (input == 1) {
		printf("If you're first your first.\n");
	} else if (input == 2) {
		printf("You aren't first, therefore you are last ");
	} else {
		 printf("%dth just means you're dead to me #dadquotes.\n", input);
	}
	return 0;
}

/**
 * @file swap.c
 *
 * @author Julian Garcia
 *
 * @date 11/4/2018
 *
 * Assignment: Lab 7
 *
 * @brief Number swapper
 *
 * @details Simple pointer version for swapping elements
 *
 * @bugs
 *
 * @todo none
 */

#include <stdio.h>

/** Prints variables
 * @param *a first variable
 * @param *b is the second element
 * @return void
 */
void print_vars(int *a, int *b)
{
	printf("a = %d\tb = %d\n", *a, *b);
}

/* a first try at writing a swap function */
/* swap the contents a with b and b with a */
/** Swaps elements
 * @param *a first element
 * @param *b second element
 * @return void
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

	printf("in function swap: ");
	print_vars(a,b);
}

int main(void)
{
	int a = 6;
	int b = 9;
	int *pa = &a;
	int *pb = &b;
	printf("before swap: ");
	print_vars(pa,pb);

	swap(pa, pb);

	printf("after swap: ");
	print_vars(pa,pb);


	return 0;
}

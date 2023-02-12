/**
 * @file array.c
 *
 * @author Julian Garcia
 *
 * @date 11/4/2018
 *
 * Assignment: Lab 7
 *
 * @brief Pointer array manipulation.
 *
 * @details Basic functions for adding, incrementing, and printing arrays using pointers
 *
 * @bugs None
 *
 * @todo none
 */

#include <stdio.h>
#include <stdlib.h>

/* pointer arthimetic version of print_array */
/** Prints the array
 * @param *a is the given array
 * @param len is the size of the array
 * @return void
 */
void print_parray(int *a, size_t len)
{
	int i = 0;

	for ( ;i < len;i++) {
		printf("%d\n", *(a + i));
	}


}


/* pointer based version */
/** Increments array
 * @param *a is the given array
 * @param len is the length of the array
 * @return void
 */
void inc_parray(int *a, size_t len)
{
	int i;


	int *p = a;



	for (i = 0; i < len; i++)
		++*p;

}



/* pointer version of add_arrays a = a + b */
/** Adds the values of two arrays
 * @param *a is an array
 * @param *b is an array
 * @param len is the length of the array
 * @return void
 */
void add_parrays(int *a, int *b, size_t len)
{
	int i = 0;
	int *c = a;


	for (; i < len; i++, a++, b++, c++)
		*c = *a + *b;

}



int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

	size_t len_a = sizeof(a)/sizeof(int);
	size_t len_b = sizeof(b)/sizeof(int);

	printf("a = ");
	print_parray(a, len_a);

	printf("\nb = ");
	print_parray(b, len_b);


	inc_parray(a, len_a);
	printf("\nafter incrementing (starts at last element)\na = ");
	print_parray(a, len_a);



	if (len_a != len_b) 	/* assume arrays are of the same length */
		exit(EXIT_FAILURE);
	else

		add_parrays(a, b, len_a);

	printf("\na = a + b\na = ");;
	print_parray(a, len_a);
	printf("\nb remains unchanged\nb = ");
	print_parray(b, len_b);


	return 0;
}

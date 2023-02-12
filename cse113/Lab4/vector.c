/**
 * @file vector.c
 *
 * @author Julian Garia
 *
 * @date 10/12/2018
 *
 * Assignment: Lab 4
 *
 * @brief Contains functions for vector_main.c
 *
 * @details produces multiple array operations
 *
 * @bugs none
 *
 */


#include<stdio.h>
#include "vector.h"

/* Place all of your functions here for your Array Problems */


/** prints out the elements of an array, one element per line
 * @param a1[] the array to print
 * @param size the size or length of the array
 */
void print_array(int a1[], size_t size)
{
	int i;

	for(i = 0; i < size; i++)

		printf("a[%d] = %d\n", i, a1[i]);
}

/** Multiplies each value of the array by a given multiplier
 * @param a1[] the given array
 * @param multiplier number to multiply array values by
 * @return void
 */
void multiply(int multiplier, int a1[], size_t size)
{

	int i = 0;

	for (i = 0; i < size; i++) {

		a1[i] = a1[i] * multiplier;
	}

}

/** Adds each value of the array by a given number
 * @param a2[] the given array
 * @param adder number to add array values by
 * @return void
 */
void add(int adder, int a2[], size_t size)
{

	int i = 0;

	for (i = 0; i < size; i++) {

		a2[i] = a2[i] + adder;
	}

}

/** Copies values of one array over to another
 * @param a3[] the array to be copied
 * @param b3[] the array which is copied to
 * @return void
 */
void copy(int a3[], int b3[], size_t size)
{

	int i = 0;

	for (i = 0; i < size; i++)

		b3[i] = a3[i];

}

/** Adds the values of two arrays together
 * @return void
 */
void add_array(int a4[], int b4[], int c4[], size_t size)
{

	int i = 0;

	for (i = 0; i < size; i++)

		c4[i] = a4[i] + b4[i];

}

/** Multiplies Two arrays together
 * @return void
 */
void mult_array(int a5[], int b5[], int c5[], size_t size)
{

	int i = 0;

	for (i = 0; i < size; i++)

		c5[i] = a5[i] * b5[i];

}

/** Multiplies two arrays inversely
 * @return void
 */
void inverse_mult_array(int a6[], int b6[], int c6[], size_t size2)
{

	int i = 0;
	int n = size2 - 1;

	for (i = 0; i < size2; i++, n--)

		c6[i] = a6[i] * b6[n];



}

/** Reverse order of array
 * @return void
 */
void reverse(int a7[], size_t size2)
{

	int tmp;
	int i = 0;
	int n = size2 - 1;

	while (i <= n) {
		tmp = a7[i];
		a7[i] = a7[n];
		a7[n] = tmp;
		i++;
		n--;
	}
}



/** generates a random integer between [0,n)
* @param n the upper bound
* @return a random integer between [0, n)
*/
int get_random_int(int n)
{
	return random() % n;
}

/** Makes array of random numbers
 * @return void
 */
void random_array(int a8[], size_t size)
{
	int i = 0;

	for (i = 0; i < size; i++)

		a8[i] = get_random_int(50);

}

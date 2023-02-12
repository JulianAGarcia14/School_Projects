/**
 * @file array.c
 *
 * @author Julian Garcia
 *
 * @date 2/14/2018
 *
 * Assignment: Lab 3
 *
 * @brief Functions for fundamental array algorithms.
 *
 * @details The functions implemented include basic counting,
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). Sorting is implemented via
 * bubble sort, a not very efficient sort, and insertion sort.
 *
 * @bugs none
 *
 * @todo implement floating point versions of the functions
 */


#include "array.h"
#include <stdio.h>


/** prints out the elements of an array, one element per line
 * @param a[] the array to print
 * @param size the size or length of the array
 */
void print_array(int a[], size_t size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

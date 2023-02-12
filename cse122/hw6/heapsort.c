/**
 * @file heapsort.c
 *
 * @author Julian Garcia
 *
 * @date 4/14/2019
 *
 * Assignment: Homework 6
 *
 * @brief  Contains function for test_heap.c
 *
 * @details Contains heapsort function.
 *
 * @bugs Simply doesn't work
 *
 * @todo
 */

#include "heapsort.h"
#include <sys/types.h>



int heapsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *), int i)
{
        /* todo generic heapsort */
        /* note you have to do pointer arthimetic with void pointers */
        /* can't use array notation, base[i] as that makes no sense as base is a void pointer  */
        /* correct way to get the i-th element is (base + i * width) */


	int largest = i;
   	int l = 2*i + 1;
   	int r = 2*i + 2;
	char *temp;



	if (l < nel && compar((base + r * width), (base + largest * width)) < 0){
		largest = l;
	}
	if (r < nel && compar((base + r * width), (base + largest * width)) > 0){
		largest = r;
	}
	if (largest != i){

		temp = ((char *)base + largest * width);
		*((char *)base + largest * width) = *((char *)base + i * width);
		*((char *)base + i * width) = *temp;


		heapsort(base, nel, width, compar, largest);
	}


        return 0;
}

 /**
 * @file lab3.c
 * 
 * @author Scott Chadde
 *
 * @date 1/1/2013
 *  
 * Assignment: Lab 3 
 *
 * @brief a program that tests the functions in array.c
 *
 * @details 
 *  
 * @bugs none
 *
 * @todo none
 */

#include <stdio.h>
#include "array.h"

int main(void)
{
	int a[] = {9, 7, 5, 3, 2, 77, 8, 12, 4, 5, 11};

	size_t size = sizeof(a) / sizeof(int);
        /* size_t size = sizeof(a) / sizeof(a[0]); */
	print_array(a, size);

	return 0;
}


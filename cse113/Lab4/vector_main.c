/**
 * @file vector.h
 *
 * @author Julian Garia
 *
 * @date 10/12/2018
 *
 * Assignment: Lab 4
 *
 * @brief calls all functions in main.c
 *
 * @details main function for vector.c, providing array values among other variables
 *
 * @bugs none
 *
 */


#include<stdio.h>
#include <time.h>
#include "vector.h"

int main(void)
{
	/*Write code for your main() for your Array Problems here*/
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	size_t size = sizeof(a1) / sizeof(int);
	printf("Original Array;\n");
	print_array(a1, size);
	printf("\n");

	printf("Multiply array\n");
	multiply(5, a1, size);
	print_array(a1, size);
	printf("\n");

	int a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	printf("Add array\n");
	add(3, a2, size);
	print_array(a2, size);
	printf("\n");

	int a3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	int b3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	copy(a3, b3, size);
	printf("Copy array\n");
	printf("Original Array:\n");
	print_array(a3, size);
	printf("\n");
	printf("Copied Array:\n");
	print_array(b3, size);
	printf("\n");

	int a4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	int b4[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	int c4[10] = {};
	printf("Add array\n");
	add_array(a4, b4, c4, size);
	print_array(c4, size);
	printf("\n");

	int a5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	int b5[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	int c5[10] = {};
	printf("Multiply two arrays\n");
	mult_array(a5, b5, c5, size);
	print_array(c5, size);
	printf("\n");

	int a6[] = {1, 2, 3, 4, 5};
	int b6[] = {6, 7, 8, 9, 10};
	int c6[5] = {};
	size_t size2 = sizeof(a6) / sizeof(int);
	printf("Inverse multiply two arrays\n");
	inverse_mult_array(a6, b6, c6, size2);
	print_array(c6, size2);
	printf("\n");

	int a7[] = {1, 2, 3, 4, 5};
	printf("Reverse order of array\n");
	reverse(a7, size2);
	print_array(a7, size2);
	printf("\n");

	srandom(time(NULL));
	int a8[10] = {};
	printf("Array of random numbers\n");
	random_array(a8, size);
	print_array(a8, size);
	printf("\n");

}

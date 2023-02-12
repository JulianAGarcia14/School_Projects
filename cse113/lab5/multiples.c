/**
* @file lab5.c
*
* @author Julian Garcia
*
* @date 3/8/2018
*
* Assignment: Lab 5
*
* @brief finds the sum for all multiples of 3 or 5 below 1000
*
* @details Uses an array and for loop to sum multiples.
*
* @bugs none
*
* @todo none
*/
#include<stdio.h>

int main(void)
{

	int a[1000];
	size_t size = sizeof(a) / sizeof(int);
	int i;
	int sum = 0;
	for(i = 0; i < size; i++) {

		a[i] = i;

		if (a[i] % 3 == 0 || a[i] % 5 == 0) {
			sum = sum + a[i];
		}
	}

	printf("sum is %d\n", sum);
	return 0;
}

/**
* @file lab5.c
*
* @author Julian Garcia
*
* @date 3/8/2018
*
* Assignment: Lab 5
*
* @brief Finds the difference between the sum of the squares of the first one hundred natural
* numbers and the square of the sum.
*
*
* @bugs none
*
* @todo none
*/
#include<stdio.h>
#include<math.h>

int main(void)
{

	int a[101];
	size_t size = sizeof(a) / sizeof(int);
	int i;
	int sum1 = 0;
	int sum2 = 0;
	int diff;
	for(i = 0; i < size; i++) {
		a[i] = i;
		sum1 = sum1 + a[i];
	}

	sum1 = pow(sum1, 2);

	for(i = 0; i < size; i++) {

		a[i] = pow(a[i], 2);
		sum2 = sum2 + a[i];


	}

	diff = sum1 - sum2;
	printf("difference is %d\n", diff);
	return 0;
}

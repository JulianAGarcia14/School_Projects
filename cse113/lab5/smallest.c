/**
* @file lab5.c
*
* @author Julian Garcia
*
* @date 3/8/2018
*
* Assignment: Lab 5
*
* @brief Finds he  smallest  positive  number  that  is  evenly  divisible  by  all  of  the  numbers from 1 to 20
*
* @bugs none
*
* @todo none
*/
#include<stdio.h>

int main(void)
{

	int i;
	int y = 1;
	for(i = 20; i >= 1; i--) {


		if (y % i != 0) {
			y = y + 1;
			i = 20;

		}
	}

	printf("sum is %d\n", y);
	return 0;
}

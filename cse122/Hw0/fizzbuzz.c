/**
 * @file fizzbuzz.c
 *
 * @author Julian Garcia
 *
 * @date 1/30/2019
 *
 * Assignment: Homework 0
 *
 * @brief Prints numbers 1-100 but replaces multiples of, 3, 5, and both with fizz, buzz, and fizzbuzz
 *
 * @details uses a modulus to find which numbers are multiples of 3 and 5
 *
 * @bugs none
 *
 * @todo
 */
#include <stdio.h>

int main() {
	//your code goes here.
	int i = 1;
	for(; i< 101; i++){

		if (i%5 == 0 && i%3 ==0) {
		       printf("FizzBuzz\n");
	        } else if (i%3 == 0) {
			printf("Fizz\n");
		} else if(i%5 == 0) {
			printf("Buzz\n");
		} else if (i%5 != 0 && i%3 !=0) {
			printf("%d\n", i);
		}

	}


	return 0;
}

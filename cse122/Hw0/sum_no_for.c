/**
 * @file sum_no_for.c
 *
 * @author Julian Garcia
 *
 * @date 1/30/2019
 *
 * Assignment: Homework 0
 *
 * @brief Finds the sum of a set of numbers using a given sum formula.
 *
 * @details finds the sum of 1-100 without using for loops and records how long this process takes.
 *
 * @bugs none
 *
 * @todo
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

unsigned long long sum_forloop(unsigned long long k);

int main(){
	unsigned long long k = 1;

	unsigned long long j;
	unsigned long long sum;

	for(j = 1;j <= 10; j++){
		clock_t start, end;
		start = clock();
		sum = sum_forloop(k);
		end = clock();



		printf("%llu|%llu|%3.24lf\n", k, sum, (double) (end - start) / CLOCKS_PER_SEC);
		k = k * 10;

	}

}

/** Sum of given set of numbers
 * @param k max number of set
 * @return sum of set
 */
unsigned long long sum_forloop(unsigned long long k)
{
      unsigned long long sum = 0;

      sum = ((3*k*(k+1))/2) - k;

      return sum;
}

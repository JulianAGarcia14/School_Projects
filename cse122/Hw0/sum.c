/**
 * @file sum.c
 *
 * @author Julian Garcia
 *
 * @date 1/30/2019
 *
 * Assignment: Homework 0
 *
 * @brief Finds the sum of a set of numbers
 *
 * @details uses a for loop to find the sum of 1-100
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
	unsigned long long i = k + 1;
	unsigned long long j;
	unsigned long long sum;

	for(j = 1;j <= 10; j++){
		clock_t start, end;
		start = clock();
		sum = sum_forloop(k);
		end = clock();



		printf("%llu|%llu|%llu|%3.24lf\n", i, k, sum, (double) (end - start) / CLOCKS_PER_SEC);
		k = k * 10;
		i = k + 1;
	}

}


/** Sum of given set of numbers
 * @param k max number of set
 * @return sum of set
 */
unsigned long long sum_forloop(unsigned long long k)
{
      unsigned long long i;
      unsigned long long sum = 0;

      for(i = 1;i <= k;i++){
	      sum = (3*i - 1) + sum;
      }

      return sum;
}

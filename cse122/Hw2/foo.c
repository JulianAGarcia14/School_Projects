/**
 * @file foo.c
 *
 * @author Julian Garcia
 *
 * @date 2/11/2019
 *
 * Assignment: Homework 2
 *
 * @brief Contains 6 functions which all find find sums using for loops
 *
 * @details Times results of multiple funcitons which use for loops to find sums.
 *
 * @bugs none
 *
 * @todo
 */


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

unsigned long foo1(unsigned long int n);
unsigned long foo2(unsigned long int n);
unsigned long foo3(unsigned long int n);
unsigned long foo4(unsigned long int n);
unsigned long foo5(unsigned long int n);
unsigned long foo6(unsigned long int n);


int main()
{
	unsigned long int sum;
	unsigned long int n;

	clock_t start, end;
	printf("foo1\n");
	for(n = 1; n <= 1000000000;) {

		start = clock();
		sum = foo1(n);
		end = clock();

		printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
		n = n*10;
	}
	printf("foo2\n");
	for(n = 1; n <= 100000;) {
		start = clock();
		sum = foo2(n);
		end = clock();
		printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
		n = n*10;
	}
	printf("foo3\n");
	for(n = 1; n <= 1000;) {
		start = clock();
		sum = foo3(n);
		end = clock();
		printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
		n = n*10;
	}
	printf("foo4\n");
	for(n = 1; n <= 100000;) {
		start = clock();
		sum = foo4(n);
		end = clock();
		printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
		n = n*10;
	}
	printf("foo5\n");
	for(n = 1; n <= 100;) {
		start = clock();
		sum = foo5(n);
		end = clock();
		printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
		n = n*10;
	}
	printf("foo6\n");
	for(n = 1; n <= 100;) {
		start = clock();
		sum = foo6(n);
		end = clock();
		printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
		n = n*10;
	}

	return 0;
}

/** Finds sum of for loop given n
 * @param n max increment
 * @return sum
 */
unsigned long foo1(unsigned long int n)
{
	unsigned long sum = 0;
	unsigned long i;
	for (i = 0; i < n; i++) {
		sum++;
	}
	return sum;

}

/** Finds sum of for loop given n
 * @param n max increment
 * @return sum
 */
unsigned long foo2(unsigned long int n)
{
	unsigned long sum = 0;
	unsigned long i;
	unsigned long j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++){
			sum++;
		}
	}
	return sum;

}

/** Finds sum of for loop given n
 * @param n max increment
 * @return sum
 */
unsigned long foo3(unsigned long int n)
{
	unsigned long sum = 0;
	unsigned long i;
	unsigned long j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n * n; j++) {
			sum++;
		}
	}
	return sum;
}

/** Finds sum of for loop given n
 * @param n max increment
 * @return sum
 */
unsigned long foo4(unsigned long int n)
{
	unsigned long sum = 0;
	unsigned long i;
	unsigned long j;
	for (i = 0; i < n; i++) {
		for(j = 0; j < i; j++) {
			sum++;
		}
	}
	return sum;
}

/** Finds sum of for loop given n
 * @param n max increment
 * @return sum
 */
unsigned long foo5(unsigned long int n)
{
	unsigned long sum = 0;
	unsigned long i;
	unsigned long j;
	unsigned long k;
	for (i = 0; i < n; i++) {
		for(j = 0; j < i * i; j++) {
			for(k = 0; k < j; k++) {
				sum++;
			}
		}
	}
	return sum;
}

/** Finds sum of for loop given n
 * @param n max increment
 * @return sum
 */
unsigned long foo6(unsigned long int n)
{
	unsigned long sum = 0;
	unsigned long i;
	unsigned long j;
	unsigned long k;
	sum = 0;
	for (i = 1; i < n; i++) {
		for(j = 1; j < i * i; j++) {
			if (j % i == 0) {
				for(k = 0; k < j; k++) {
					sum++;
				}
			}
		}
	}
	return sum;
}

/**
 * @file foo10.c
 *
 * @author Julian Garcia
 *
 * @date 2/11/2019
 *
 * Assignment: Homework 2
 *
 * @brief Essentially the same as foo.c but with conditional execution
 *
 * @details 6 for loops that end at 10 times the value of foo.c
 *
 * @bugs none
 *
 * @todo
 */


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//#define ONE 1;

//#define TWO 2;

//#define THREE 3

//#define FOUR 4

//#define FIVE 5
#define SIX 6


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
	#ifdef ONE
		printf("foo1\n");
		for(n = 1000000000; n <= 10000000000; n += 1000000000) {

			start = clock();
			sum = foo1(n);
			end = clock();

			printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);

		}
	#endif

	#ifdef TWO
		printf("foo2\n");
		for(n = 100000; n <= 1000000; n += 100000) {
			start = clock();
			sum = foo2(n);
			end = clock();
			printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);

		}
	#endif

	#ifdef THREE
		printf("foo3\n");
		for(n = 1000; n <= 10000; n += 1000) {
			start = clock();
			sum = foo3(n);
			end = clock();
			printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);

		}
	#endif

	#ifdef FOUR
		printf("foo4\n");
		for(n = 100000; n <= 1000000; n += 100000) {
			start = clock();
			sum = foo4(n);
			end = clock();
			printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);

		}
	#endif

	#ifdef FIVE
		printf("foo5\n");
		for(n = 100; n <= 1000; n += 100) {
			start = clock();
			sum = foo5(n);
			end = clock();
			printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);

		}
	#endif

	#ifdef SIX
		printf("foo6\n");
		for(n = 100; n <= 1000; n += 100) {
			start = clock();
			sum = foo6(n);
			end = clock();
			printf("%lu|%lu|%lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);

		}
	#endif

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

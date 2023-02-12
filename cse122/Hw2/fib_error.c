/**
 * @file fib_error.c
 *
 * @author Julian Garcia
 *
 * @date 2/11/2019
 *
 * Assignment: Homework 2
 *
 * @brief Prints out the fibonacci sequence up until just before overflow occurs
 *
 * @details compares the fibonacci sequence found with a for loop to the approximate formula for the nth term
 *
 * @bugs none
 *
 * @todo
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

unsigned max_n(void);
double fib(unsigned n);
unsigned long * fib_array(unsigned n);

int main()
{
	unsigned int n;
	unsigned long * arr;
	unsigned int i;
	double error; 

	int j = 2;
	n = max_n();
	arr = fib_array(n);

	for (i = 0; i <  n; i++) {
		printf("f[%d] = %lu \n", i, arr[i]);
	}
	for (i = 3; i <  n; i++) {

		if (floor(fib(j)) != arr[i]) {
			error = ((fib(j) - arr[i])/fib(j))*100;
			printf("Error in %d term of formula Fibonacci\n", i);
			printf("Terms differ by %d\n", (int) floor(fib(j) - arr[i]));
			printf("Percentage error %1.18lf %%\n\n", error);
		}
		j++;
	}
	free(arr);

	return 0;
}


 /** Determines the largest n you can find before overflow occurs
  * @return largest n possible without overflow
  */
unsigned max_n(void)
{
	double n = 0;
	double phi = (1 + sqrt(5)) / 2;

	n = log(sqrt(5)*ULONG_MAX) / log(phi);

	double nn = floor(n);
	unsigned int nnn = (unsigned int) nn;
	return nnn + 1;
}

/** Determines the fibonacci number of the given n
 * @param n the current term of the sequence.
 * @return the fibonacci number
 */
double fib(unsigned n)
{
	double phi = (1 + sqrt(5)) / 2;
	double nphi = (1 - sqrt(5)) / 2;
	double F = pow(phi, n + 1);
	F = F - (pow(nphi, n + 1));
	F = F/sqrt(5);
	return F;


}

/** Creates a dynamic array holding a fibonacci sequence to the nth term.
 * @param n the current term of the sequence.
 * @return the fibonacci sequence
 */
unsigned long * fib_array(unsigned n)
{
	unsigned long i;
	unsigned long t1 = 0;
	unsigned long t2 = 1;
	unsigned long nextTerm;

        unsigned long *arr = (unsigned long *)malloc(n *sizeof(unsigned long));

	arr[0] = 0;
	arr[1] = 1;

    	for (i = 2; i <= n; i++) {

        	nextTerm = t1 + t2;
        	t1 = t2;
        	t2 = nextTerm;

		arr[i] = nextTerm;

	}

   	return arr;
}

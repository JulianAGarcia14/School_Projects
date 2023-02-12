/**
 * @file fib.c
 *
 * @author Julian Garcia
 *
 * @date 2/11/2019
 *
 * Assignment: Homework 2
 *
 * @brief Prints out the fibonacci number for a given term
 *
 * @details uses a for loop to calculate the fibonacci number and can only go up to 93.
 *
 * @bugs none
 *
 * @todo
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include <unistd.h> /* getopt and optarg */

unsigned max_n(void);
double fib(unsigned n);
unsigned long * fib_array(unsigned n);
int check_n(unsigned n, unsigned *max_n);

int main(int argc, char **argv)
{

	unsigned int n;
	unsigned long * arr;
	unsigned int i;
	unsigned int c;
	int error;

	if (argc != 3) {
		printf("usage: %s -n INTEGER\n", argv[0]);
		return -1;
	}

	n = max_n();
	arr = fib_array(n);

	while((c = getopt(argc, argv, "n:")) != -1) {
		switch(c) {
		case 'n':
			i = (unsigned)atoi(optarg);
			error = check_n(i, &n);
			if (error != 0){
				return -1;
			}
			break;
		case 'h':
			printf("usage: %s -n INTEGER\n", argv[0]);
			return 0;
		default:
			printf("something went wrong\n");
			return -1;
		}
	}

	printf("The %d Fibonacci term is %lu \n", i, arr[i]);

	free(arr);

	return 0;
}


/** Checks to see if the given n term is possible to compute without overflow
 * @param n the given nth term
 * @param max_n the largest the n can be
 * @return -1 or 0 for false and true respectively
 */
int check_n(unsigned n, unsigned *max_n)
{

	if(n > *max_n) {
		printf("n is too large -- overflow will occur\n");
		printf("the largest Fibonacci term that can be calculated is 93\n");
		return -1;
	} else {
		return 0;
	}

}


 /** Determines the largest n you can find before overflow occu
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

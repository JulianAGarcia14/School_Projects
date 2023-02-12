/**
 * @file main.c
 *
 * @author Julian Garcia
 *
 * @date 3/25/2019
 *
 * Assignment: Blackbox
 *
 * @brief contains main function and written functions to analyze blackbox function
 *
 * @details functions create sorted,inverse, and shuffled list to evaluate blackbox.
 *
 * @bugs none
 *
 * @todo
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#include "blackbox.h"

//#define ONE 1
//#define TWO 2
//#define THREE 3
#define FOUR 4
//#define FIVE 5
//#define SIX 6
//#define SEVEN 7

void seed(void);
void swap(unsigned long *x, unsigned long *y);
unsigned long * sorted_list(unsigned long n);
unsigned long * shuffle_list(unsigned long n);
unsigned long * reverse_list(unsigned long n);
unsigned long random_number(void);


int main(int argc, char **argv) {

	if (argc != 2 || atoi(argv[1]) < 0) {
		printf("usage: declare number to be tested\n");
		printf("       must be non-negative number\n");
		return -1;
	}


	unsigned long n = atoi(argv[1]);
	int i;


	int msec;
	clock_t time_elapsed;
	//unsigned long *list = sorted_list(n);
	//unsigned long *list = reverse_list(n);
	unsigned long *list = shuffle_list(n);

	FILE *out2 = fopen("plot.txt", "w");

	#ifdef ONE
		/*use n = 100*/
		for(i = 0; i < 10; i++) {

			time_elapsed = clock();

			/* test something here; e.g. */
			/* function_3(list, n); */
			function_1(n);

			time_elapsed = clock() - time_elapsed;
			msec = time_elapsed * 1000 / CLOCKS_PER_SEC;

			printf("Function 1:\n");
			printf("Time taken: %d.%03d seconds\n", msec/1000, msec%1000);
			printf("CPU-Time elapsed: %d ticks\n", (int) time_elapsed);
			fprintf(out2, "%lu %d\n", n, (int) time_elapsed);
			n = n + 100;

		}

		free(list);
	#endif

	#ifdef TWO
		/*use n = 10*/
		for(i = 0; i < 20; i++) {

			time_elapsed = clock();

			/* test something here; e.g. */
			/* function_3(list, n); */
			function_2(n);

			time_elapsed = clock() - time_elapsed;
			msec = time_elapsed * 1000 / CLOCKS_PER_SEC;

			printf("Function 2:\n");
			printf("Time taken: %d.%03d seconds\n", msec/1000, msec%1000);
			printf("CPU-Time elapsed: %d ticks\n", (int) time_elapsed);
			fprintf(out2, "%lu %d\n", n, (int) time_elapsed);

			n = n + 1;
		}
		free(list);
	#endif

	#ifdef THREE
		/* use n = 100000 for shuffled list, and use i < 10*/
		/* use n = 10 for reverse list, and use i < 7*/
		/* use n = 100000 for sorted list, and use i < 7*/
		for(i = 0; i < 7; i++) {

			time_elapsed = clock();

			/* test something here; e.g. */
			/* function_3(list, n); */
			function_3(list, n);

			time_elapsed = clock() - time_elapsed;
			msec = time_elapsed * 1000 / CLOCKS_PER_SEC;

			printf("Function 3:\n");
			printf("Time taken: %d.%03d seconds\n", msec/1000, msec%1000);
			printf("CPU-Time elapsed: %d ticks\n", (int) time_elapsed);
			fprintf(out2, "%lu %d\n", n, (int) time_elapsed);

			/* n = n + 100000;  for shuffled list*/
			/* n = n * 10;  for reverse list*/
		  	n = n * 10; /*for sorted list*/
			free(list);
			/*Make sure to change declaration when changing these*/
			//list = sorted_list(n);
			//list = reverse_list(n);
			list = shuffle_list(n);
		}

		free(list);
	#endif

	#ifdef FOUR
		/*use n = 10*/
		for(i = 0; i < 8; i++) {

			time_elapsed = clock();

			/* test something here; e.g. */
			/* function_3(list, n); */
			function_4(n);

			time_elapsed = clock() - time_elapsed;
			msec = time_elapsed * 1000 / CLOCKS_PER_SEC;

			printf("Function 4:\n");
			printf("Time taken: %d.%03d seconds\n", msec/1000, msec%1000);
			printf("CPU-Time elapsed: %d ticks\n", (int) time_elapsed);
			fprintf(out2, "%lu %d\n", n, (int) time_elapsed);
			n = n * 10;
		}

		free(list);
	#endif

	#ifdef FIVE
		/*use n = 1000000*/
		for(i = 0; i < 10; i++) {

			time_elapsed = clock();

			/* test something here; e.g. */
			/* function_3(list, n); */
			function_5(n);

			time_elapsed = clock() - time_elapsed;
			msec = time_elapsed * 1000 / CLOCKS_PER_SEC;

			printf("Function 5:\n");
			printf("Time taken: %d.%03d seconds\n", msec/1000, msec%1000);
			printf("CPU-Time elapsed: %d ticks\n", (int) time_elapsed);
			fprintf(out2, "%lu %d\n", n, (int) time_elapsed);
			n = n * 10;
		}

		free(list);
	#endif

	#ifdef SIX
		/* use n =  1*/
		for(i = 0; i < 100; i++) {

			time_elapsed = clock();

			/* test something here; e.g. */
			/* function_3(list, n); */
			function_6(list, n);

			time_elapsed = clock() - time_elapsed;
			msec = time_elapsed * 1000 / CLOCKS_PER_SEC;

			printf("Function 6:\n");
			printf("Time taken: %d.%03d seconds\n", msec/1000, msec%1000);
			printf("CPU-Time elapsed: %d ticks\n", (int) time_elapsed);
			fprintf(out2, "%lu %d\n", n, (int) time_elapsed);
			n = n + 1000;
			free(list);
			/*Make sure to change declaration when changing these*/
			//list = sorted_list(n);
			//list = reverse_list(n);
			list = shuffle_list(n);
		}
		free(list);
	#endif

	#ifdef SEVEN
		/* use n =  1*/
		for(i = 0; i < 10; i++) {
			time_elapsed = clock();

			/* test something here; e.g. */
			/* function_3(list, n); */
			function_7(n);

			time_elapsed = clock() - time_elapsed;
			msec = time_elapsed * 1000 / CLOCKS_PER_SEC;

			printf("Function 7:\n");
			printf("Time taken: %d.%03d seconds\n", msec/1000, msec%1000);
			printf("CPU-Time elapsed: %d ticks\n", (int) time_elapsed);
			fprintf(out2, "%lu %d\n", n, (int) time_elapsed);
			n = n + 1;
		}

		free(list);
	#endif
	fclose(out2);


	return 0;

}


/** Generates sorted list of 1 to n using dynamically allocated array
 * @param n max number of list
 * @return sorted list
 */
unsigned long * sorted_list(unsigned long n)
{
	/* generate a sorted list */
	unsigned long i;
	unsigned long *list = malloc(n * sizeof(unsigned long));
	for(i = 0; i < n; i++) {
		*(list+i) = i;
	}
	return list;
}

/** Generates shuffled list of 1 to n using dynamically allocated array
 * @param n max number of list
 * @return shuffled list
 */
unsigned long * shuffle_list(unsigned long n)
{
	/* *list is a sorted list, of size n */
	unsigned long i;
	unsigned long j;
	unsigned long *list = sorted_list(n);
	seed();
	/* step back from the end of the list */
	for(i = n - 1; i > 0; i--) {
		/* pick a random element between 0 and i to swap */
		j = random_number() % (i+1);
		swap(list+i, list+j);
	}
	return list;
}

/** Generates reverse list of 1 to n using dynamically allocated array
 * @param n max number of list
 * @return reversed list
 */
unsigned long * reverse_list(unsigned long n)
{
	/* generate a reversed list */
	unsigned long i;
	unsigned long j = n;
	unsigned long *list = malloc(n * sizeof(unsigned long));
	for(i = 0; i < n; i++) {

		*(list+i) = j;
		j--;
	}
	return list;

}

/** Swaps two numbers using pointers
 * @param x, y numbers to be swapped
 * @return void
 */
void swap(unsigned long *x, unsigned long *y)
{
	unsigned long temp = *x;
    	*x = *y;
    	*y = temp;

}


/**
*  call this to seed the random number generator rand()
*  uses a simple seed -- the number of seconds since the epoch
*  call once before using nrand and similiar functions that call rand()
*/
void seed(void)
{
	srand((unsigned int)time(NULL));

}

/* random_number: generates a pseudo-random
long unsigned between 0 and 2^64-1
seed random() with srandom(time(NULL)) before you call this */
unsigned long random_number(void) {

	unsigned long n, p, r;
	int i;
	n = 0;
	for(i = 0, p = 1; i < 8; i++, p *= 256) {
		/* we have p = 256^i */
		/* random value between 0 and 255 */
		r = random() % 256;
		/* add this pseudo-random byte to n */
		n += r * p;
	}
	/* repeat 8 times, so we have 64 pseudo-random bits */
	return n;
}

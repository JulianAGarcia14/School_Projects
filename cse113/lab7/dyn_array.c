/**
 * @file dyn_array.c
 *
 * @author Julian Garcia
 *
 * @date 11/4/2018
 *
 * Assignment: Lab 7
 *
 * @brief Functions for pointer array algorithms.
 *
 * @details The functions implemented include basic counting,
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). All of this is done using dynamically
 * allocated memory.
 *
 * @bugs For some reason, error comes up saying there is a "double free" or some sort of extra freeing happening.
 *
 * @todo none
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define MALLOC_FAILED 1000

int find_midpoint(int max, int min);
float find_average(int *u, size_t size, int summation);
int find_min(int *u, int max, size_t size);
int find_max(int *u, size_t size);
int add(int *u, size_t size);
void print_array(int *u, size_t size, int max, int min, float ave, int mid);

int main(void)
{

	int max;
	int min;
	float ave;
	int mid;
	int summation;
	int a[] = {4, 6, 2, 4, 9, 11, 14, 16, 1, 15, 3};

	int *u;


	size_t size = (sizeof(a) / sizeof(int));

	u = malloc(size * sizeof(int));

	if (u == NULL) {
		printf("malloc failed. goodbye...\n");
		exit(MALLOC_FAILED);
	}

	u = a;

	summation = add(u, size);
	max = find_max(u, size);
	min = find_min(u, max, size);
	ave = find_average(u, size, summation);
	mid = find_midpoint(max, min);


	print_array(u, size, max, min, ave, mid);


	free(u);

	return 0;
}


/** prints out the elements of an array, one element per line
 * @param *u the array to print
 * @param size the size or length of the array
 */
void print_array(int *u, size_t size, int max, int min, float ave, int mid)
{
	int i;

	for(i = 0; i < size; i++) {

		fprintf( stdout, "a[%d] = %d\n", i, *(u + i));
	}
	fprintf( stdout, "Max = %d\nMin = %d\nMid = %d\n Average = %lf\n", max, min, mid, ave);

}

/** finds the max of the array
 * @param *u is the given array
 * @return maximum array value
 */
int find_max(int *u, size_t size)
{
	int i = 0;
	int big = 0;

	for (i = 0; i < size; i++) {

		if (*(u + i) > big) {
			big = *(u + i);
		}
	}

	return big;
}

/** Finds the minimum value
 * @param *u the given array
 * @return the minimum value
 */
int find_min(int *u, int max, size_t size)
{
	int i = 0;
	int small = max;

	for (i = 0; i < size; i++) {

		if (*(u + i) < small) {
			small = *(u + i);
		}
	}

	return small;
}


/** Finds the sum of the array
 * @param *u the given array
 * @return The sum of all values of the array
 */
int add(int *u, size_t size)
{
	int sum = 0;
	int i = 0;

	for (i = 0; i < size; i++) {

		sum = *(u + i) + sum;
	}

	return sum;
}


/** Finds the mean of the array
 * @param *u the given array
 * @return The mean value of the array
 */
float find_average(int *u, size_t size, int summation)
{
	float sum = summation;
	return sum / size;

}

/** Finds the midpoint of the array
 * @param min the minimum of the array
 * @param max the maximum of the array
 * @return the midpoint
 */
int find_midpoint(int max, int min)
{
	float mid;
	mid = (max + min) / 2;
	return mid;

}

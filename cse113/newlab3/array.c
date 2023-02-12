/**
 * @file array.c
 *
 * @author Julian Garcia
 *
 * @date 10/1/2018
 *
 * Assignment: Lab 3
 *
 * @brief Functions for fundamental array algorithms.
 *
 * @details The functions implemented include basic counting,
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). Sorting is implemented via
 * bubble sort, a not very efficient sort, and insertion sort.
 *
 * @bugs none
 *
 * @todo implement floating point versions of the functions
 */


#include "array.h"
#include <stdio.h>


/** prints out the elements of an array, one element per line
 * @param a[] the array to print
 * @param size the size or length of the array
 */
void print_array(int a[], size_t size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

/** prints a summmary of array values
 * @return void
 */
void print_summary(size_t size, int max, int min, float mid, int ltmid, int gtmid, int search, int sum, float ave, int med, int even, int odd, int divide)
{
	/* use %zu for printing size_t types */
	printf("size of array = %zu\n", size);
	printf("max of array = %d\n", max);
	printf("min of array = %d\n", min);
	printf("midpoint of array = %f\n", mid);
	printf("Count of numbers less than the midpoint is %d\n", ltmid);
	printf("Count of numbers greater than the midpoint is %d\n", gtmid);

	if (search == -1) {
		printf("The midpoint is not found in the list\n");
	} else {

		printf("The midpoint is found in the list\n");
	}

	printf("The sum of all the elements of the array is %d\n", sum);
	printf("The average of the list  is %lf\n", ave);
	printf("The median of the list is %d\n", med);
	printf("The amount of even numbers is %d\n", even);
	printf("The amount of odd numbers is %d\n", odd);
	printf("The amount of numbers divisible by the given number (117) is %d\n", divide);

}

/** finds the max of the array
 * @param a[] is the given array
 * @return maximum array value
 */
int find_max(int a[], size_t size)
{
	int i = 0;
	int big = 0;

	for (i = 0; i < size; i++) {

		if (a[i] > big) {
			big = a[i];
		}
	}

	return big;
}


/** Finds the minimum value
 * @param a[] the given array
 * @return the minimum value
 */
int find_min(int a[], int max, size_t size)
{
	int i = 0;
	int small = max;

	for (i = 0; i < size; i++) {

		if (a[i] < small) {
			small = a[i];
		}
	}

	return small;
}

/** Finds the midpoint of the array
 * @param min the minimum of the array
 * @param max the maximum of the array
 * @return the midpoint
 */
float midpoint(int max, int min)
{
	float mid;
	mid = (max + min) / 2.0;
	return mid;

}

/** Finds all values less than, equal to, or greater than a given number
 * @param type is the type of search
 * @param a[] the given array
 * @param x is the given number
 * @return Count of numbers LT, GT, or EQ to given number
 */
int get_count(int a[], size_t size, int type, int x)
{
	int count = 0;
	int i = 0;

	switch (type) {

	case LT:


		for (i = 0; i < size; i++) {

			if (a[i] < x) {
				count = count + 1;
			}
		}


		break;

	case LE:


		for (i = 0; i < size; i++) {

			if (a[i] <= x) {
				count = count + 1;
			}
		}


		break;

	case GT:


		for (i = 0; i < size; i++) {

			if (a[i] > x) {
				count = count + 1;
			}
		}


		break;

	case GE:


		for (i = 0; i < size; i++) {

			if (a[i] >= x) {
				count = count + 1;
			}
		}


		break;

	case EQ:


		for (i = 0; i < size; i++) {

			if (a[i] == x) {
				count = count + 1;
			}
		}


		break;

	}

	return count;
}

/** Searches for the desired element
 * @param y the number you're looking for
 * @param a[] the given array
 * @return the desired element or confirmation it isnt in the array
 */
int linear_search(int y, int a[], size_t size)
{
	int i = 0;
	int index;

	while (i <= size && y != a[i]) {

		i = i + 1;

	}

	if (i <= size) {

 		index = i;
	} else{

		index = -1;
	}
	return index;
}

/** Finds the sum of the array
 * @param a[] the given array
 * @return The sum of all values of the array
 */
int add(int a[], size_t size)
{
	int sum = 0;
	int i = 0;

	for (i = 0; i < size; i++) {

		sum = sum + a[i];
	}

	return sum;
}

/** Finds the mean of the array
 * @param a[] the given array
 * @return The mean value of the array
 */
float average(int a[], size_t size)
{
	float sum = add(a, size);
	return sum / size;

}

/** performs a bubble sort
 * @param a[] the given array
 * @return void
 */
void bubble_sort(int a[], size_t size)
{
	int i = 0;
	int j = 0;
	int tm;
	int n = size;

	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < (n - i - 1); j++) {

			if (a[j] > a[j + 1]) {

				tm = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tm;
			}
		}

	}
}

/** Performs an insertion sort
 * @param a[] the given array
 * @return void
 */
void insertion_sort(int a[], size_t size)
{
	int x;
	int k;
	int j;

	for (k = 1; k < size; k++) {

		x = a[k];
		j = k - 1;

		while (j >= 0 && a[j] > x) {

			a[j + 1] = a[j];
			j = j - 1;
			a[j + 1] = x;

		}


	}

}

/** Reverses the order of the array
 * @param a[] the given array
 * @return void
 */
void reverse(int a[], size_t size) {

	int tmp;
	int i = 0;
	int n = size - 1;

	while (i <= n) {
		tmp = a[i];
		a[i] = a[n];
		a[n] = tmp;
		i++;
		n--;
	}
}

/** Finds the median of the array
 * @param a[] the given array
 * @return The median
 */
int median(int a[], size_t size)
{
	int n = size;
	int median;

	if (size % 2 == 0) {

		median = (a[n / 2] + a[(n / 2) + 1]) / 2;
	} else {

		median = a[(n + 1) / 2];
	}

	return median;
}

/** Counts the amount of even numbers
 * @param a[] the given array
 * @return count of even numbers
 */
int count_even(int a[], size_t size)
{
	int count = 0;
	int i = 0;

	for (i = 0; i < size; i++) {

		if (a[i] % 2 == 0) {

			count = count +1;

		}
	}
	return count;
}

/** Counts the number of odd numbers
 * @param a[] the given array
 * @return count of odd numbers
 */
int count_odd(int a[], size_t size)
{
	int count = 0;
	int i = 0;

	for (i = 0; i < size; i++) {

		if (a[i] % 2 != 0) {

			count = count +1;

		}
	}
	return count;
}

/** counts amount of numbers divisible by given number
 * @param a[] the given array
 * @param divisor number to divide array values by
 * @return count of divisible numbers
 */
int divisible_count(int divisor, int a[], size_t size)
{

	int count = 0;
	int i = 0;

	for (i = 0; i < size; i++) {

		if (a[i] % divisor == 0) {

			count = count + 1;
		}
	}

	return count;
}

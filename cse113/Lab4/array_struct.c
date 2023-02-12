/**
 * @file array.struct.c
 *
 * @author Julian Garia
 *
 * @date 10/12/2018
 *
 * Assignment: Lab 4
 *
 * @brief Main file for array_struct assignment
 *
 * @details Contains multiple array indexing functions
 *
 * @bugs none
 *
 */

#include "array_struct.h"
#include <stdio.h>


int main(void)
{

	struct data_t data[SIZE];
	struct summary_t summary;

	/* data initialization calls */
	init_array(data, 0, 'A', 23, 74);
	init_array(data, 1, 'B', 22, 64);
	init_array(data, 2, 'C', 19, 68);
	init_array(data, 3, 'D', 20, 76);
	init_array(data, 4, 'E', 22, 62);

	summary.max_height = height_max(data, SIZE);
	summary.max_age = age_max(data, SIZE);

	summary.min_height = height_min(data, SIZE);
	summary.min_age = age_min(data, SIZE);

	summary.height_average = average_height(data, SIZE);
	summary.age_average = average_age(data, SIZE);

	print_array(data, SIZE);
	print_summary(summary);


	return 0;
}

/** Prints values for age and height
 * @param summary all the variables needed for height, age, and averagess
 * @return void
 */
void print_summary(struct summary_t summary)
{
       printf("\n");
       printf("index for max age = %d\n", summary.max_age);
       printf("index for max height = %d\n", summary.max_height);
       printf("index for min age = %d\n", summary.min_age);
       printf("index for min height = %d\n", summary.min_height);
       printf("Average height is %d\n", summary.height_average);
       printf("Average age is %d\n", summary.age_average);

}

/** Initializes array by placing values for age, id, and age
 * @param data[] the array to fill
 * @param index the value at which to store the personal information
 * @param id the id number of the person
 * @param years the age of the person
 * @param inches the height of the person
 * @return void
 */
void init_array(struct data_t data[], int index, char id, int years, int inches)
{
	data[index].subject = id;
	data[index].height = inches;
	data[index].age = years;


}

/** finds the max of the array
 * @param a[] is the given array
 * @return maximum array value
 */
int height_max(struct data_t data[], int size)
{
	int i = 0;
	int big = 0;
	int index;

	for (i = 0; i < size; i++) {

		if (data[i].height > big) {
			big = data[i].height;
			index = i;
		}
	}

	return index;
}

/** finds the max of the array
 * @param a[] is the given array
 * @return maximum array value
 */
int age_max(struct data_t data[], int size)
{
	int i = 0;
	int big = 0;
	int index;

	for (i = 0; i < size; i++) {

		if (data[i].age > big) {
			big = data[i].age;
			index = i;
		}
	}

	return index;

}



/** Finds the minimum value
 * @param a[] the given array
 * @return the minimum value
 */
int height_min(struct data_t data[], int size)
{
	int i = 0;
	int index;
	int small = data[size - 1].height;

	for (i = 0; i < size; i++) {

		if (data[i].height < small) {
			small = data[i].height;
			index = i;
		}
	}

	return index;

}

/** Finds the minimum value
 * @param a[] the given array
 * @return the minimum value
 */
int age_min(struct data_t data[], int size)
{
	int i = 0;
	int index;
	int small = data[size - 1].age;

	for (i = 0; i < size; i++) {

		if (data[i].age < small) {
			small = data[i].age;
			index = i;
		}
	}

	return index;

}

/** Finds the average height of the list
 * @param a[] the given array
 * @return The mean value of the array
 */
float average_height(struct data_t data[], int size)
{
	int sum = 0;
	int i = 0;

	for (i = 0; i < size; i++) {

		sum = sum + data[i].height;
	}

	return sum / size;

}

/** Finds the average height of the list
 * @param a[] the given array
 * @return The mean value of the array
 */
float average_age(struct data_t data[], int size)
{
	int sum = 0;
	int i = 0;

	for (i = 0; i < size; i++) {

		sum = sum + data[i].age;
	}

	return sum / size;

}


/** prints out the elements of an array, one element per line
 * @param data[] the array to print
 * @param size the size or length of the array
*/
void print_array(struct data_t data[], int size)
{
	int i;
	printf("For height\n");
	for(i = 0; i < size; i++) {

		printf("index %d = %d\n", i, data[i].height);

	}
	printf("\n");

	int j;
	printf("For age\n");
	for(j = 0; j < size; j++) {

		printf("index %d = %d\n", j, data[j].age);

	}
	printf("\n");

	int k;
	printf("For subject\n");
	for(k = 0; k < size; k++) {

		printf("index %d = %c\n", k, data[k].subject);

	}

}

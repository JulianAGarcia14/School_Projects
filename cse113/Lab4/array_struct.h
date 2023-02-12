/**
 * @file array.struct.h
 *
 * @author Julian Garia
 *
 * @date 10/12/2018
 *
 * Assignment: Lab 4
 *
 * @brief header file for array_struct.c
 *
 * @details contains function declarations for array_struct
 *
 * @bugs none
 *
 */



#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_


#define SIZE 5

struct data_t {

	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	char subject; 	/* one capital letter id for subject */

};

struct summary_t {

	int max_height;
	int min_height;
	int max_age;
	int min_age;
	int age_average;
	int height_average;

};

void init_array(struct data_t data[], int index, char id, int years, int inches);
int height_max(struct data_t data[], int size);
int age_max(struct data_t data[], int size);
int height_min(struct data_t data[], int size);
int age_min(struct data_t data[], int size);
float average_height(struct data_t data[], int size);
float average_age(struct data_t data[], int size);
void print_array(struct data_t data[], int size);
void print_summary(struct summary_t summary);


#endif

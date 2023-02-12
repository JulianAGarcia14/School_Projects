/**
 * @file vector.h
 *
 * @author Julian Garia
 *
 * @date 10/12/2018
 *
 * Assignment: Lab 4
 *
 * @brief header file for vector.c
 *
 * @details see vector.c for details
 *
 * @bugs none
 *
 */

#ifndef VECTOR_H_
#define VECTOR_H_

/* Place all of your function prototypes here for your Array Problems, #1-8 */

#include <stdlib.h> 		/* for size_t declaration */

/* function declarations go here */
void print_array(int a1[], size_t size);
void multiply(int multiplier, int a1[], size_t size);
void add(int adder, int a2[], size_t size);
void copy(int a3[], int b3[], size_t size);
void add_array(int a4[], int b4[], int c4[], size_t size);
void mult_array(int a5[], int b5[], int c5[], size_t size);
void inverse_mult_array(int a6[], int b6[], int c6[], size_t size2);
void reverse(int a7[], size_t size2);
void random_array(int a8[], size_t size);

#endif

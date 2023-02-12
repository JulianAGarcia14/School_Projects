/**
 * @file array.h
 *
 * @author Julian Garcia
 *
 * @date 10/1/2018
 *
 * Assignment: Lab 3
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *
 * @bugs none
 *
 * @todo add floating point versions of the functions
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h> 		/* for size_t declaration */

/* function declarations go here */
void print_array(int a[], size_t size);

#define LT 10
#define LE 11
#define GT 12
#define GE 13
#define EQ 14

int find_max(int a[], size_t size);

int find_min(int a[], int max, size_t size);

float midpoint(int max, int min);

int get_count(int a[], size_t size, int type, int x);

int linear_search(int y, int a[], size_t size);

int add(int a[], size_t size);

float average(int a[], size_t size);

void bubble_sort(int a[], size_t size);

void insertion_sort(int a[], size_t size);

void reverse(int a[], size_t size);

int median(int a[], size_t size);

int count_even(int a[], size_t size);

int count_odd(int a[], size_t size);

int divisible_count(int divisor, int a[], size_t size);

void print_summary(size_t size, int max, int min, float mid, int ltmid, int gtmid, int search, int sum, float ave, int med, int even, int odd, int divide);

#endif

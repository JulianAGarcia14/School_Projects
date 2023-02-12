/**
 * @file cube_binary.c
 *
 * @author Julian Garcia
 *
 * @date 1/30/2019
 *
 * Assignment: Homework 0
 *
 * @brief solves for cube root of numbers 1-100
 *
 * @details uses a binary search to find cube roots.
 *
 * @bugs none
 *
 * @todo
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double cubicRoot(double n);
double differences(double n,double mid);

int main(){

	double n;

	for(n = 1; n <= 100; n++) {
        	cubicRoot(n);
	}
        return 0;

}


/** Determines how accurate the current approximation is
 * @param n the number we're finding the root of
 * @param m the current middle value
 * @return difference between mid^3 and n
 */
double differences(double n,double mid)
{
    if (n > (mid*mid*mid))
        return (n-(mid*mid*mid));
    else
        return ((mid*mid*mid) - n);
}



/** Finds and prints cube root of given number
 * @param n the number to find the root of
 * @return cube root
 */
double cubicRoot(double n)
{
    double start = 0;
    double end = n;
    int i = 0;

    double accuracy = 0.000000001;

    while (1)
    {
        double mid = (start + end)/2;
        double error_amt = differences(n, mid);

	if (error_amt <= accuracy){

		printf("%d|%0.0lf|%0.10lf\n", i, n, mid);
		return mid;
	}

        if ((mid*mid*mid) > n) {
        	end = mid;
	}

        else {
        	start = mid;
	}
	i++;
    }
}

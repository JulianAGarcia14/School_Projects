/**
 * @file newton_sqrt.c
 *
 * @author Julian Garcia
 *
 * @date 1/30/2019
 *
 * Assignment: Homework 0
 *
 * @brief Finds square root of a number using newton's method.
 *
 * @details Uses a for loop to approximate the square root to a certain accuracy.
 *
 * @bugs none
 *
 * @todo
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void newtonroot(float a, float x);

int main(){

	float x = 1.0;
	float a;

	for(a = 1;a <= 100; a++){
		x = a;
		while (x*x > a){
			x = x/2;
		}
		newtonroot(a, x);

	}

}


/** Finds and prints square root of given number
 * @param a the number to find the root of
 * @param x an early approximation which is less than the square root
 * @return void
 */
void newtonroot(float a, float x)
{
	int i = 0;
	float approx = 0;
	while(trunc(10000. * x) != trunc(10000. * approx)){
		approx = x;
      		x = x - (x*x - a) / (2*x);

		i++;
	}
	printf("%d|%0.0lf|%0.9lf\n", i, a, x);
}

/**
 * @file newton_cube.c
 *
 * @author Julian Garcia
 *
 * @date 1/30/2019
 *
 * Assignment: Homework 0
 *
 * @brief Finds the cube root of a number using newton's method
 *
 * @details Uses for loops to run the approximation of a cube root by newtoon's method
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
		while (x*x*x > a){
			x = x/2;
		}
		newtonroot(a, x);

	}

}

/** Finds and prints cube root of given number
 * @param a the number to find the cube root of
 * @param x an early approximation which is less than the cube root
 * @return void
 */
void newtonroot(float a, float x)
{
	int i = 0;
	float approx = 0;
	while(trunc(1000. * x) != trunc(1000. * approx)){
		approx = x;
      		x = x - (x*x*x - a) / (3*x*x);

		i++;
	}
	printf("%d|%0.0lf|%0.9lf\n", i, a, x);
}

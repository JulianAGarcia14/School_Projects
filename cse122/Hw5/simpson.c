/**
 * @file simpson.c
 *
 * @author Julian Garcia
 *
 * @date 3/31/2019
 *
 * Assignment: Homework 5
 *
 * @brief Finds integrals using simpsons rule
 *
 * @details Finds integral of e^x, sinx, cosx, ln(x), sqrt(x), to an accuracy of 100 subdivisions
 *
 * @bugs none
 *
 * @todo
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

double integrate(double (*f)(double x), double a, double b, int n);

int main(void)
{
	double e_area;
	double sin_area;
	double cos_area;
	double ln_area;
	double sqrt_area;
	int n = 100;
	/* integrate with sin, cos, exp */
	e_area = integrate(exp, 0.0, 1.0, n);
	printf("integral of e^x from 0 to 1 is %lf\n", e_area);
	sin_area = integrate(sin, 0.0, M_PI, n);
	printf("integral of sin(x) from 0 to Pi is %lf\n", sin_area);
	cos_area = integrate(cos, 0.0, M_PI, n);
	printf("integral of cos(x) from 0 to Pi is %lf\n", cos_area);
	ln_area = integrate(log, 0.5, 2.0, n);
	printf("integral of ln(x) from 0.5 to 2 is %lf\n", ln_area);
	sqrt_area = integrate(sqrt, 0.0, 10, n);
	printf("integral of sqrt(x) from 0 to 10 is %lf\n", sqrt_area);


	return 0;
}

/** Finds integral of given function
 * @param *f(x) given function
 * @param a beginning of given interval
 * @param b end of given interval
 * @param n number of subdivisions (accuracy)
 * @return area integral of function
 */
double integrate(double (*f)(double x), double a, double b, int n)
{
	double h;		/* height of rectangle */
	double w;		/* width of rectangle */
	double ww;
	double area = 0.0;	/* area of rectangle */
	double x;		/* the domain value */
	int i;


	w = (b - a) / n;
	ww = w/3.0;

	for (i = 1, x = a; i <= n; i++) {
		x = a + i*w;
		if(i == 1||i == n){
			h = (*f)(x);
		} else if(i % 2 == 0) {
			h = (*f)(x);
			h = 4.0*h;
		} else if(i % 2 != 0) {
			h = (*f)(x);
			h = 2.0*h;
		}
		area += (ww * h);
	}

	return area;		/* area under the curve */

}

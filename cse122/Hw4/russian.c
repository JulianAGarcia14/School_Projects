/**
 * @file russian.c
 *
 * @author Julian Garcia
 *
 * @date 2/28/2019
 *
 * Assignment: Homework 4
 *
 * @brief Multiplies numbers using russian peasant algorithm
 *
 * @details Parses input file to multiply numbers using russian peasant algorithm.
 *
 * @bugs none
 *
 * @todo
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>

 #define MAX 4096

 int russian(int m, int n);


 int main(void)
 {
	 int m = 32;
	 int n = 27;
	 int result;


	 char s[MAX];
	 char *d;
	 while(fgets(s, MAX, stdin)) {
		 /* code to process string */
		 d = strtok(s, " ");
		 m = atoi(d);
		 d = strtok(NULL, "\n");
		 n = atoi(d);
		 result = russian(m, n);
		 printf("%d * %d = %d\n", m, n, result);
	 }


 }

 /** Multiplies number using russian peasant method
  * @param n, m numbers to be multiplieds
  * @return Result of peasant algorithm
  */
int russian(int m, int n)
{
	int sum_m;
	if((n%2) == 0){
		sum_m = 0;
	} else {
		sum_m = m;
	}

	while(n >= 1){
		n = n/2;
		m = m*2;
		if((n%2) != 0){
			sum_m = sum_m + m;
		}
	}
	return sum_m;
}

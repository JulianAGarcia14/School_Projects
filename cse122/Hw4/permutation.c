/**
 * @file permutation.c
 *
 * @author Julian Garcia
 *
 * @date 2/28/2019
 *
 * Assignment: Homework 4
 *
 * @brief
 *
 * @details
 *
 * @bugs none
 *
 * @todo
 */

// Note LOG(3n)/ log(n)

 #include<stdio.h>
 #include<stdlib.h>
 #include<limits.h>
 #include<math.h>
 #include <time.h>

 #include "randint.h"

 #define ONE 1

 #define TWO 2

 #define THREE 3

unsigned long * lucky(unsigned n);
unsigned long * used(unsigned n);
unsigned long * knuth(unsigned n);
unsigned long nrand(unsigned range);
void swap(unsigned long *x, unsigned long *y);
void seed(void);


 int main()
 {
	 unsigned int n;
	 unsigned long * arr1;
	 unsigned long * arr2;
	 unsigned long * arr3;
	 unsigned int i = 1;
	 unsigned int j = 0;
	 double t = 0;

	 seed();

	 #ifdef ONE
	 	unsigned int n_n[] = {250, 500, 1000, 2000};
		printf("\nBegin Lucky runs \n");
	 	while(j < 4) {

	 		n = n_n[j];

	 		printf("run     n      time\n");
	 		for(i = 1; i <=10; i++) {
	 			clock_t start, end;
	 			start = clock();
	 			arr1 = lucky(n);
	 			end = clock();

	 			printf("%d	%d	%8.4lf\n", i, n, (double) (end - start) / CLOCKS_PER_SEC);
				t = t + ((double) (end - start) / CLOCKS_PER_SEC);
	 			/* Code for seeing array values, have to declare k to use
				for(k = 1; k<=n; k++){
					printf("%d %lu\n", k, arr1[k]);
	 			}*/
 			}
		printf("avg for n = %d for lucky is %lf\n\n", n, t/10);
		j++;
		}
		free(arr1);
	#endif

	#ifdef TWO
		j = 0;
		printf("\nBegin used runs \n");
		unsigned int n_n1[] = {2500, 5000, 10000, 20000, 40000, 80000};
		while(j < 6) {
			n = n_n1[j];//2500,5000,10000,20000,40000,80000;

	       		printf("run     n      time\n");
	       		for(i = 1; i <=10; i++) {
		       		clock_t start, end;
		       		start = clock();
		       		arr2 = used(n);
		       		end = clock();

		       		printf("%d	%d	%8.4lf\n", i, n, (double) (end - start) / CLOCKS_PER_SEC);
		       		t = t + ((double) (end - start) / CLOCKS_PER_SEC);
		       		/*Code for seeing array values, have to declare k to use
		       		for(j = 1; j<=n; j++){
			       		printf("%d %lu\n", j, arr2[j]);
		       		}*/
	       		}
	       		printf("avg for n = %d for used is %lf\n\n", n, t/10);
			j++;
			free(arr2);
		}

       #endif

       #ifdef THREE
       		j = 0;
       		unsigned int n_n2[] = {10000,20000,40000,80000,160000,320000,640000};
		printf("\nBegin knuth runs \n");
       		while(j < 7) {
	       		n = n_n2[j]; //10000,20000,40000,80000,160000,320000,640000

	      		printf("run     n      time\n");
	      		for(i = 1; i <=10; i++) {
		      		clock_t start, end;
		      		start = clock();
		      		arr3 = knuth(n);
		      		end = clock();

		      		printf("%d	%d	%8.4lf\n", i, n, (double) (end - start) / CLOCKS_PER_SEC);
		      		t = t + ((double) (end - start) / CLOCKS_PER_SEC);
		      		/* Code for seeing array values, have to declare k to use
		      		for(j = 1; j<=n; j++){
			      		printf("%d %lu\n", j, arr3[j]);
		      		}*/
	      		}
	      		printf("avg for n = %d for used is %lf\n\n", n, t/10);
	      		j++;
			free(arr3);
      		}

        #endif


	 return 0;
 }

unsigned long * lucky(unsigned n)
{
	unsigned long i;
	unsigned long j;


	unsigned long *arr1 = (unsigned long *)malloc((n + 1) *sizeof(unsigned long));

	arr1[0] = 0;

	for (i = 1; i <= n; i++) {

		arr1[i] = nrand(n);
		j = i - 1;
		for(j = i -1; j >= 1; j--){
			if(arr1[i] == arr1[j]){
				i--;
				break;
			}
		}
	}

	return arr1;
}

unsigned long * used(unsigned n)
{
	unsigned long i;


	unsigned long *ar = (unsigned long *)malloc((n + 1) *sizeof(unsigned long));
	unsigned long *ar2 = (unsigned long *)malloc((n + 1) *sizeof(unsigned long));

	ar[0] = 0;




	for (i = 1; i <= n; i++) {
		ar[i] = nrand(n);
		while(ar2[ar[i]] == 1) {
			ar[i] = nrand(n);
		}
		ar2[ar[i]] = 1;

	}

	free(ar2);
	return ar;


}

unsigned long * knuth(unsigned n)
{
	unsigned int i = 1;
	unsigned long j;

	unsigned long *arr = (unsigned long *)malloc((n + 1) *sizeof(unsigned long));
	for(i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (i = 1; i < n; i++) {
		j = nrand(n);
		swap(&arr[i], &arr[j]);
	}
	return arr;
}

void swap(unsigned long *x, unsigned long *y)
{
	unsigned long temp = *x;
    	*x = *y;
    	*y = temp;

}

/**
*  returns a uniform random integer between 0 <= rand num <= range
*  @param range defines the range of the random number [0,range]
*  @return the generated random number
*/
unsigned long nrand(unsigned int range)
{
	unsigned long num = 0;
	while(num == 0){
		num = rand() % (range + 1);
	}

	return num;
}

/**
*  call this to seed the random number generator rand()
*  uses a simple seed -- the number of seconds since the epoch
*  call once before using nrand and similiar functions that call rand()
*/
void seed(void)
{
	srand((unsigned int)time(NULL));

}

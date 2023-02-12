#include<stdio.h>

void array_mod(int a[], int di[], size_t size, int divisor);

int main(void)
{

	int a[] = {13, 44, 85, 23, 72, 99, 100, 108, 222, 1084};
	int di[] = {13, 44, 85, 23, 72, 99, 100, 108, 222, 1084};
	int divisor = 4;
	size_t size = sizeof(a) / sizeof(int);

	array_mod(a, di, size, divisor);

}


void array_mod(int a[], int di[], size_t size, int divisor)
{
	int i = 0;
	int product;


	for (i = 0; i < size; i++) {


		printf("%d\t", a[i]);
		product = a[i] % divisor;


		if (product == 0) {

			di[i] = 1;
			printf("%d\n", di[i]);
		} else {

			di[i] = 0;
			printf("%d\n", di[i]);
		}

	}

}

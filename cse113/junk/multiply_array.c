#include<stdio.h>

void array_multiply_range(int a[], size_t size, int start, int stop);

int main(void)
{
	int start = 1;
	int stop = 4;
	int a[] = {6, 3, 5, 2, 3, 2, 4};
	size_t size = sizeof(a) / sizeof(int);

	array_multiply_range(a, size, start, stop);

}


void array_multiply_range(int a[], size_t size, int start, int stop)
{
	int product = 1;

	if (start < stop) {
		for (; start <= stop; start++) {


		 	product = a[start] * product;
			printf("%d\n", product);
		}

	}  else if (start > stop) {

		for (; start >= stop; start--) {


		 	product = a[start] * product;
			printf("%d\n", product);
		}

	} else {

		printf("%d is equal to %d\n", start, stop);
	}

}

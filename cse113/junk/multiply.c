#include<stdio.h>

void multiply_range(int start, int stop);

int main(void)
{
	int start;
	int stop;
	printf("select the start of the function\n");
	scanf("%d", &start);
	printf("select the stop of the function\n");
	scanf("%d", &stop);
	printf("\n");

	multiply_range(start, stop);

}


void multiply_range(int start, int stop)
{
	int product = 1;

	if (start < stop) {
		for (; start <= stop; start++) {

			product = start * product;
			printf("%d\n", product);
		}

	}  else if (start > stop) {

		for (; start >= stop; start--) {

		 	product = start * product;
			printf("%d\n", product);
		}

	} else {

		printf("%d is equal to %d\n", start, stop);
	}

}

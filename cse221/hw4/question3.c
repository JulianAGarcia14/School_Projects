#include <stdio.h>

void swap(int *a, int *b);

int main()
{
	int a = 1;
	int b = 0;
	printf("Before xor swap a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("After xor swap a = %d, b = %d\n", a, b);

}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

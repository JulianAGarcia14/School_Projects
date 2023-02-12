#include<stdio.h>

void print_array(int first[], size_t size);

int main(void)
{
	int first[1000];
	size_t size = sizeof(first) / sizeof(int);

	print_array(first, size);


}

void print_array(int first[], size_t size)
{
	int i;
	for (i = 1; i <= size; i++) {

		printf("%d\n", i);

	}

}

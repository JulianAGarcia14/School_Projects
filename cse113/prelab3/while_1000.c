#include<stdio.h>

int main(void)
{
	int first[1000];
	size_t size = sizeof(first) / sizeof(int);
	int i = size;

	while (i >= 2) {

		i = i - 1;
		printf("%d\t", i);
	}

}

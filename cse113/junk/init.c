#include<stdio.h>

int main(void)
{
	int first[1000];
	int i = 0;
	size_t size = sizeof(first) / sizeof(int);

	for (i = 0; i <= size; i++) {

		first[i] = i;
		printf("%d\n", first[i]);

	}

}

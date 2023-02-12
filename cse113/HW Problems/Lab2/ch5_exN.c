#include<stdio.h>

int main(){

	printf("------------Exercise 1--------------");
	printf("Part a:\n");
	int i = 2;
	int j = 3;
	int k = i * j == 6;
	printf("%d\n", k);

	printf("Part b\n");
	i = 5;
	j = 10;
	k = 1;
	printf("%d\n", k > i < j);

	printf("Part c\n");
	i = 3;
	j = 2;
	k = 1;
	printf("%d\n", i < j == j < k);

	printf("Part d\n");
	i = 3;
	j = 4;
	k = 5;
	printf("%d\n", i % j + i < k);

	printf("-------------Exercise 7------------");
	printf("If i is 17\n");
	i = 17;
	printf("%d\n", i >= 0 ? i : -i);
	printf("If i is -17\n");
	i = -17;
	printf("%d\n", i >= 0 ? i : -i);
	printf("It comes out as 17 either way.\n");

	printf("------------Exercise 8--------------\n");
	int age = 4;
	int teenager;
	if ( 19 >= age >= 13) {
		teenager = 1; /*1 means true here*/
	} else {
		teenager = 0; /*0 means false here*/
	}

	printf("%d\n", teenager);

	return 0;



}

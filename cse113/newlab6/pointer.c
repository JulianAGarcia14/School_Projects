#include<stdio.h>


int main()
{
	int *p;
	int a, b;
	a = 0;
	b = 1;

	//corrected Julian Garcia 10/28/2018
	p = &a;
	//p = a;
	printf("%d\n", *p);

	//corrected Julian Garcia 10/28/2018
	p = &b;
	//b = &p;

	printf("%d\n", b);

 	return 0;
}

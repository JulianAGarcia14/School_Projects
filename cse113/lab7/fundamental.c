#include <stdio.h>
//#include <stdlib.h>


int main(void)
{
	double p = 3.14159;
	double *pp = &p;
	*pp = 2.71828;

	printf("Address of p is %p, value of p is %lf\n", &p, p);
	printf("Value of pointer is %lf, address of pointer is %p\n", *pp, pp);



	return 0;

}

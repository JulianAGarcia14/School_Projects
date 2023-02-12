#include <stdio.h>
#include <stdlib.h>

void print_celcius(float F, float C);

int main(int argc, char **argv)
{
        //your code goes here
	float F;
	float celcius;
	if(argc==1) {
		/* Default case if no argument is given */
		printf("usage: F2c F\n");
	} if(argc>1 && argc<3) {
		F = atof(argv[1]);
		celcius = (F-32)/1.8;
		print_celcius(F, celcius);
	} else if(argc>2)
		printf("usage: F2c F\n");
        return 0;
}

void print_celcius(float F, float C)
{
	printf("F = %lf", F);
	printf("C = %lf\n", C);
}

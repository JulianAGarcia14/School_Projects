#include<stdio.h>

/*f is 1.8c + 32*/
float conversionf(float c);
float conversionc(float f);

int main()
{
        float c;
        float f;

	printf("What is the Celcius you want to convert to F?\n");
	scanf("%f", &c);
	printf("What is the F you want to convert to C?\n");
	scanf("%f", &f);

        float degf = conversionf(c);
        float degc = conversionc(f);
        printf("%lf degrees fahrenheit converts to %lf celcius\n", f, degc);
        printf("%lf degrees celcius converts to %lf degrees fahrenheit\n", c, degf);

        return 0;
}

float conversionf(float c)
{
        return 1.8*c + 32;

}

float conversionc(float f)
{
        return (f-32)/1.8;

}

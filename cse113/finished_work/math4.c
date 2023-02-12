#include<stdio.h>

float finddollar(float eu);
float findeuro(float dol);

int main()
{
        float dol;
        float eu;

	printf("Type the amount of dollars you want to convert to Euros.\n");
	scanf("%f", &dol);
	printf("Type the amount of Euros you want to convert to dollars.\n");
	scanf("%f", &eu);

        float fndol = finddollar(eu);
        float fneu = findeuro(dol);
        printf("%lf dollars converts to %lf euros.\n", dol, fneu);
        printf("%lf euros converts to %lf dollars.\n", eu, fndol);
        return 0;

}

float finddollar(float eu)
{
        return 1.8*eu;


}

float findeuro(float dol)
{
        return dol/1.8;


}

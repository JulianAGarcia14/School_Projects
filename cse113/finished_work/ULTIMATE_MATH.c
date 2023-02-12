#include<stdio.h>
#include<math.h>

float conversionf(float cel);
float conversionc(float f);

float finddollar(float eu);
float findeuro(float dol);

double area_circle(double r);
double area_washer(double r1 , double r2);

double quadratic(float a, float b, float c);
double quadratic2(float a, float b, float c);
double disc(float a, float b, float c);

int main()
{
        float cel = 23;
        float f = 70;
        float degf = conversionf(cel);
        float degc = conversionc(f);
        printf("\n");
        printf("%lf degrees fahrenheit converts to %lf celcius\n", f, degc);
        printf("%lf degrees celcius converts to %lf degrees fahrenheit\n", cel, degf);
        printf("\n");

        float dol = 24.2;
        float eu = 7.4;
        float fndol = finddollar(eu);
        float fneu = findeuro(dol);
        printf("%lf dollars converts to %lf euros.\n", dol, fneu);
        printf("%lf euros converts to %lf dollars.\n", eu, fndol);
        printf("\n");

        double r = 1.0;
        double r1 = 4.0;
        double r2 = 3.0;
        double ac = area_circle(r);
        double aw = area_washer(r1, r2);
        printf("area of circle with radius %lf = %lf\n", r, ac);
        printf("area of washer with outer radius %lf, and inner radius %lf is %lf\n", r1, r2, aw);
        printf("\n");

        float c = -3;
        float a = 2;
        float b = -5;
        double answer = quadratic(a, b, c);
        double alternate = quadratic2(a, b, c);
        double d = disc(a, b, c);

        if (d < 0)  {
                printf("Solutions are imaginary\n");
        }  else if (d > 0) {

                printf("The given formula is %lf*X^2 + %lf*X + %lf = 0\n", a, b, c);
                printf("The solution of the formula for x is %lf or %lf\n", answer, alternate);
                printf("\n");
        }  else {
                printf("The given formula is %lf*X^2 + %lf*X + %lf = 0\n", a, b, c);
                printf("The only solution of the formula for x is %lf\n", answer);
                printf("\n");

        }


        return 0;
}

float conversionf(float cel)
{
        return 1.8*cel + 32;

}

float conversionc(float f)
{
        return (f-32)/1.8;

}

float finddollar(float eu)
{
        return 1.8*eu;


}

float findeuro(float dol)
{
        return dol/1.8;


}

double area_circle(double r)
{
        double M_Pi = 3.14;
        return M_Pi * pow(r, 2.0);

}

double area_washer(double r1, double r2)
{

        return area_circle(r1) - area_circle(r2);

}

double quadratic(float a, float b, float c)
{
        /*The quadratic formula divided into eight parts for the sake of PEMDAS*/

        float first = pow(b, 2);
        float second = 4*a*c;
        float third = first - second;
        float fourth = -1*b;
        float fifth = sqrt(third);
        float sixth = fourth + fifth;
        float seventh = 2*a;
        float eighth = sixth/seventh;
        return (eighth);

}

double quadratic2(float a, float b, float c)
{

        float first = pow(b, 2);
        float second = 4 * a * c;
        float third = first - second;
        float fourth = -1 * b;
        float fifth = sqrt(third);
        float sixth = fourth - fifth; /*The + of the sixth operation is replaced with a - as per the formula*/
        float seventh = 2 * a;
        float eighth = sixth / seventh;
        return (eighth);

}

/**
 * calculate the discriminant of a quadratic function
 * @param a coef of x^2 term
 * @param b coef of x term
 * @param c coef of constant
 * @return the disriminant
*/

double disc(float a, float b, float c)
{
        float first = pow(b, 2);
        float second = 4 * a * c;
        float third = first - second;
        float fifth = sqrt(third);
        return(fifth);

}

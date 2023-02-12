/**
 * @file bigmath.c
 *
 * @author Julian Garia
 *
 * @date 9/5/2018
 *
 * Assignment: Prelab 1
 *
 * @brief Contains multiple conversions and math functions.
 *
 * @details Converts euros to dollars, celcius to fahrenheit, finds area of circle and washer.
 *
 * @bugs none
 *
 */



#include<stdio.h>
#include<math.h>

float conversionf(float cel);
float conversionc(float f);

float finddollar(float eu);
float findeuro(float dol);

double area_circle(double r);
double area_washer(double r1 , double r2);

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

        return 0;
}

/** Converts Celcius to Fahrenheit
 * @param cel temperature in celciue
 * @return temperature in fahrenheit
*/
float conversionf(float cel)
{
        return 1.8*cel + 32;

}

/** Converts Fahrenheit to Celcius
 * @param f temperature in fahrenheit
 * @return temperature in celcius
*/
float conversionc(float f)
{
        return (f-32)/1.8;

}

/** Converts euros to dollars
 * @param eu amount of euros
 * @return dollars
*/
float finddollar(float eu)
{
        return 1.8*eu;


}
/** Converts dollars to euros
 * @param dol amount of dollars
 * @return euros
*/
float findeuro(float dol)
{
        return dol/1.8;


}

/** calculate the area of a circle
 * @param r radius of circle
 * @return the area of the circle
*/
double area_circle(double r)
{
        double M_Pi = 3.14;
        return M_Pi * pow(r, 2.0);

}

/** calculate the area of a washer
 * @param r1 radius of outer circle
 * @param r2 radius of inner circle
 * @return the area of the washer
*/
double area_washer(double r1, double r2)
{

        return area_circle(r1) - area_circle(r2);

}

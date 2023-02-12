#include<stdio.h>
#include<math.h>

double quadratic(float a, float b, float c);
double quadratic2(float a, float b, float c);

int main()
{

        float c =-3;
        float a =2;
        float b =-5;
        double answer = quadratic(a, b, c);
        double alternate = quadratic2(a, b, c);
        printf("The formula is %lf*X^2 + %lf*X + %lf = 0\n", a, b, c);
        printf("The solution is %lf or %lf\n", answer, alternate);
        return 0;
}

double quadratic(float a, float b, float c)
{
        /*The quadratic formula divided into eight parts for the sake of PEMDAS*/

        float first = pow(b, 2);
        float second = 4 * a *c;
        float third = first - second;
        float fourth = -1 * b;
        float fifth = sqrt(third);
        float sixth = fourth + fifth;
        float seventh = 2 * a;
        float eighth = sixth/seventh;
        return (eighth);

}

double quadratic2(float a, float b, float c)
{
        /*In this the + of the sixth operation is replaced with a - as per the formula*/
        float first = pow(b, 2);
        float second = 4.0 * a * c;
        float third = first - second;
        float fourth = -1.0 * b;
        float fifth = sqrt(third);
        float sixth = fourth - fifth;
        float seventh = 2.0 * a;
        float eighth = sixth/seventh;
        return (eighth);

}

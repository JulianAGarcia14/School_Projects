#include<stdio.h>
#include<math.h>

double area_circle(double r);
double area_washer(double r1 , double r2);

int main()
{
        double r = 1.0;
        double r1 = 4.0;
        double r2 = 3.0;
        double ac = area_circle(r);
        double aw = area_washer(r1, r2);
        printf("area of circle with radius %lf = %lf\n", r, ac);
        printf("area of washer with radius (%lf, %lf) = %lf\n", r1, r2, aw);
        return 0;

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

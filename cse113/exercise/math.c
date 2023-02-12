#include<stdio.h>
#include<math.h>

#define PI = 3.14

/*a=pir2*/
/*M_pi   pow=power*/

int main()
{
        double area, pi=3.14, r=5.0, sr=2.5;
        printf("what's the radius? (It's 5 stop pressuring me)\n");
	scanf("%f", &r);
        double rr=r-sr;

        area=(pi*rr*rr - pi*rr*rr);

        printf("the area is %f\n", area);

        return 0;
}

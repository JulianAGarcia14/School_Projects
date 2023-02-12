/**
*  @file lab1.c
*  @brief Solves geometry questions for rectangles, regular polygons, triangles and circles.
*  @author Julian Garcia
*  @date 2/5/2018
*  @bug None
*/

#include<stdio.h>
#include<math.h>

double area_rectangle(int al, int aw);

double perimeter_rectangle(int pl, int pw);

double diagonal_rectangle(int dl, int dw);

double area_circle(double r);

double circumference(double cr);

double area_triangle(double ht, double bt);

double hypotenuse(double hype_h, double hype_b);

double perimeter_triangle(double per_h, double per_b);

double exterior_angle(int na);

double interior_angle(int ni);

double area_regular_polygon(double s, int n);

double M_Pi = 3.141593;

int main()
{
	printf("\n");
	printf("!!!!!!!!!!!!!!!!!!!!!WELCOME TO MY MATH CAVE!!!!!!!!!!!!!!!!!!!!\n");
	printf("\n");
	printf("----------------- Regular Polygon Calculations ------------------\n");
	int n;
	double s;
	printf("\n");
	printf("For the area of a regular polygon----------------------\n");
	printf("\n");
	printf("Enter the number of sides of the regular polygon (interger)\n");
	scanf("%d", &n);
	printf("Enter the size of one side of the regular polygon\n");
	scanf("%lf", &s);
	double ap = area_regular_polygon(s, n);
	printf("The area of a regular polygon %d sides of %lf length is %lf\n", n, s, ap);
	printf("-------------------------------------------------------\n");

	printf("\n");
	int ni;
	printf("\n");
	printf("For the interior angle of a regular polygon------------\n");
	printf("\n");
	printf("Enter the number of sides (interger) of the polygon\n");
	scanf("%d", &ni);
	double in_a = interior_angle(ni);
	printf("\n");
	printf("The interior angle of a regular polygon with %d sides is %lf\n", ni, in_a);
	printf("-------------------------------------------------------\n");

	int na;
	printf("\n");
	printf("For the exterior angle of a regular polygon------------\n");
	printf("\n");
	printf("Enter the number of sides(int) of the polygon\n");
	scanf("%d", &na);
	double ex = exterior_angle(na);
	printf("The eterior angle of a regular polygon with %d sides is %lf\n", na, ex);
	printf("\n");
	printf("----------------------------------------------------------------\n");

	printf("\n");
	printf("-------------------- Triangle Calculations ----------------------\n");
	double per_h;
	double per_b;
	printf("\n");
	printf("For the perimeter of a triangle-----------------------\n");
	printf("\n");
	printf("Enter the height of the triangle\n");
	scanf("%lf", &per_h);
	printf("Enter the base of the triangle\n");
	scanf("%lf", &per_b);
	double perim = perimeter_triangle(per_h, per_b);
	printf("The perimeter of a triangle with %lf height and %lf base is %lf\n", per_h, per_b, perim);
	printf("------------------------------------------------------\n");

	double hype_h;
	double hype_b;
	printf("\n");
	printf("For the hypotenuse of a triangle-------------------\n");
	printf("\n");
	printf("Enter the height of the triangle:\n");
	scanf("%lf", &hype_h);
	printf("Enter the base of the triangle\n");
	scanf("%lf", &hype_b);
	double hype = hypotenuse(hype_h, hype_b);
	printf("The hypotenuse of a triangle with %lf height and %lf base is %lf\n", hype_h, hype_b, hype);
	printf("---------------------------------------------------\n");


	double ht;
	double bt;
	printf("\n");
	printf("For the area of a triangle-------------------------\n");
	printf("\n");
	printf("Enter the height of the triangle:\n");
	scanf("%lf", &ht);
	printf("Enter the size of the base:\n");
	scanf("%lf", &bt);
	double at = area_triangle(ht, bt);
	printf("The area of a triangle with %lf height and %lf base is %lf\n", ht, bt, at);
	printf("\n");
	printf("-----------------------------------------------------------------\n");

	printf("\n");
	printf("------------------------ Circle Calculations --------------------\n");
	double cr;
	printf("\n");
	printf("For the circumference of a circle------------------\n");
	printf("\n");
	printf("Enter the radius of the circle:\n");
	scanf("%lf", &cr);
	double cc = circumference(cr);
	printf("The circumference of a circle with %lf radius is %lf\n", cr, cc);
	printf("---------------------------------------------------\n");

	double r;
	printf("\n");
	printf("For the area of a circle---------------------------\n");
	printf("\n");
	printf("Enter the radius of the circle:\n");
	scanf("%lf", &r);
	double ac = area_circle(r);
	printf("The area of a circle with radius %lf is %lf\n", r, ac);
	printf("\n");
	printf("-----------------------------------------------------------------\n");

	printf("\n");
	printf("-------------------- Rectangle Calculations ---------------------\n");
	double dl;
	double dw;
	printf("\n");
	printf("For the diagonal of a rectangle--------------------\n");
	printf("\n");
	printf("Enter the length of the rectangle:\n");
	scanf("%lf", &dl);
	printf("Enter the width of the rectangle\n");
	scanf("%lf", &dw);
	double dr = diagonal_rectangle(dl, dw);
	printf("The diagonal of a rectangle of %lf width and %lf length is %lf\n", dw, dl, dr);
	printf("---------------------------------------------------\n");

	double pl;
	double pw;
	printf("\n");
	printf("For the perimeter of a rectangle-------------------\n");
	printf("\n");
	printf("Enter the length of the rectangle:\n");
	scanf("%lf", &pl);
	printf("Enter the width of the rectangle:\n");
	scanf("%lf", &pw);
	double pr = perimeter_rectangle(pl, pw);
	printf("The perimeter of a rectangle of %lf length and %lf width is %lf\n", pl, pw, pr);
	printf("----------------------------------------------------\n");


	double al;
	double aw;
	printf("\n");
	printf("For the area of a rectangle-------------------------\n");
	printf("\n");
	printf("Enter the length of the rectangle:\n");
	scanf("%lf", &al);
	printf("Enter the width of the rectangle:\n");
	scanf("%lf", &aw);
	double ar = area_rectangle(al, aw);
	printf("The area of a rectangle of %lf lenght and %lf with is %lf\n", al, aw, ar);
	printf("\n");
	printf("-----------------------------------------------------------------\n");
	printf("\n");

	return 0;
}

/**
*  Finds area of a regular polygon
*  @param n the number of sides
*  @param s the length of each side
*  @return the area of the given polygon
*/
double area_regular_polygon(double s, int n)
{

	return pow(s, 2) * n / 4 * tan(M_Pi/n);

}

/**
*  Finds the interior angle of a regular polygon
*  @param ni the number of sides
*  @return the size of one interior angle in degrees
*/
double interior_angle(int ni)
{
	return 180 * (ni - 2);

}

/**
*  Finds the size of an exterior angle on a regular polygon
*  @param na the number of sides of the polygon
*  @return the size of a single exterior angle
*/
double exterior_angle(int na)
{
	return 360 / na;

}

/**
*  Adds three sides of a triangle
*  @param per_h the height of the triangle
*  @param per_b the base of the triangle
*  @param hype the hypotenuse of the triangle given the height and base
*  @return the sum of Per_h + per_b + hype
*/
double perimeter_triangle(double per_h, double per_b)
{
	double hype = hypotenuse(per_h, per_b);
	return per_h + per_b + hype;

}

/**
*  Finds the hypotenuse of a triangle given its height and base
*  @param hype_h the height of the triangle
*  @param hype_b the base of the triangle
*  @return the result of the pythagorean theorem
*/
double hypotenuse(double hype_h, double hype_b)
{
	return sqrt(pow(hype_h, 2) + pow(hype_b, 2));

}

/**
*  Finds the area of a triangle
*  @param ht the height of the triangle
*  @param bt the base of the triangle
*  @return the result of 1/2 base * height
*/
double area_triangle(double ht, double bt)
{
	return 0.5 * bt * ht;

}

/**
*  Finds the circumference of a circle
*  @param cr the radius of the circle
*  @return the result of 2 * pi * radius
*/
double circumference(double cr)
{
	return 2 * M_Pi * cr;

}

/**
*  Finds the area of a circle
*  @param r the radius of the circle
*  @return the result of pi * r^2
*/
double area_circle(double r)
{
	return M_Pi * pow(r, 2);

}

/**
*  Finds the diagonal of a rectangle
*  @param dw the width of the rectangle
*  @param dl the length of the rectangle
*  @return the diagonal of the rectangle
*/
double diagonal_rectangle(int dw, int dl)
{
	return sqrt(pow(dw, 2) + pow(dl, 2));

}

/**
*  Finds the area of a rectangle
*  @param al the length of the rectangle
*  @param aw the width of the rectangle
*  @return the result of width * length
*/
double area_rectangle(int al, int aw)
{
	return al * aw;
}

/**
*  Finds the perimeter of a rectangle
*  @param pl the length of the rectangle
*  @param pw the width of the rectangle
*  @return the result of 2 * length + 2 * width
*/
double perimeter_rectangle(int pl, int pw)
{
	return 2 * pl + 2 * pw;
}

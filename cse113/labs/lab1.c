/**
*  @file lab1.c
*
*  @author Julian Garcia
*
*  @brief Solves geometry questions for rectangles, regular polygons, triangles and circles.
*
*  Assignment: Lab 1
*
*  @date 9/10/2018
*
*  @details
*
*  @bug None
*/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define M_Pi 3.141593

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

/*double M_Pi = 3.141593;*/

int main()
{
	int in;
	int tmp;

	/*Regular Polygon Declarations*/
	/*Area of polygon*/
	int n;
	double s;
	/*Interior angle*/
	int ni;
	/*Exterior angle*/
	int na;

	/*Triangle declarations*/
	/*For Perimeter*/
	double per_h;
	double per_b;
	/*For hypotenuse*/
	double hype_h;
	double hype_b;
	/*For area*/
	double ht;
	double bt;

	/*Circle declarations*/
	/* For the area of a circle*/
	double r;
	/*For circumference*/
	double cr;

	/*Rectangle Declarations*/
	/*For the diagonal*/
	double dl;
	double dw;
	/*For the perimeter*/
	double pl;
	double pw;
	/*For the area*/
	double al;
	double aw;

	printf("\n");
	printf("!!!!!!!!!!!!!!!!!!!!!WELCOME TO MY MATH CAVE!!!!!!!!!!!!!!!!!!!!\n");
	printf("\n");

	printf("Indicate which type of operation you wish to perform\n");
	printf("P regular polygon operations\n");
	printf("T for triangle operations\n");
	printf("C for circle operations\n");
	printf("R for rectangle operations\n");

	while ((tmp = getchar()) != '\n')
	in = tmp;

	switch (in) {

	case 'P':
	case 'p':

		printf("----------------- Regular Polygon Calculations ------------------\n");

		printf("Indicate the operation you want to perform\n");
		printf("A for the area\n");
		printf("I for the interior angle\n");
		printf("E for the exterior angle\n");


		while ((tmp = getchar()) != '\n')
		in = tmp;

		switch (in) {

		case 'A':
		case 'a':


			printf("\n");
			printf("For the area of a regular polygon----------------------\n");
			printf("\n");
			printf("Enter the number of sides of the regular polygon (interger)\n");
			scanf("%d", &n);
			printf("Enter the size of one side of the regular polygon\n");
			scanf("%lf", &s);
			double ap = area_regular_polygon(s, n);

			if (s < 0 || n < 0) {

				printf("Error: Sides and length cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The area of a regular polygon %d sides of %lf length is %lf\n", n, s, ap);
				printf("-------------------------------------------------------\n");
			}

			break;

		case 'I':
		case 'i':

			printf("\n");

			printf("\n");
			printf("For the interior angle of a regular polygon------------\n");
			printf("\n");
			printf("Enter the number of sides (interger) of the polygon\n");
			scanf("%d", &ni);
			double in_a = interior_angle(ni);

			if (ni < 0) {

				printf("Error: Number of sides cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

			printf("\n");
			printf("The interior angle of a regular polygon with %d sides is %lf\n", ni, in_a);
			printf("-------------------------------------------------------\n");
			}
			break;

		case 'E':
		case 'e':


			printf("\n");
			printf("For the exterior angle of a regular polygon------------\n");
			printf("\n");
			printf("Enter the number of sides(int) of the polygon\n");
			scanf("%d", &na);
			double ex = exterior_angle(na);

			if (na < 0) {

				printf("Error: The number of sides cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The eterior angle of a regular polygon with %d sides is %lf\n", na, ex);
				printf("\n");
				printf("----------------------------------------------------------------\n");
			}

			break;

		default:
			printf("\n");
			printf("%c is not an option.\n", in);
			printf("(•_•)\n");
			printf("( •_•)>⌐■-■\n");
			printf("(⌐■_■)\n");
			printf("Later nerd \n");
			printf("\n");
			return 2;

		}
		break;

	case 'T':
	case 't':

		printf("\n");
		printf("-------------------- Triangle Calculations ----------------------\n");

		printf("\n");
		printf("Indicate the operation you want to perform\n");
		printf("P for the perimeter\n");
		printf("H for the hypotenuse\n");
		printf("A for the area\n");
		printf("\n");

		while ((tmp = getchar()) != '\n')
		in = tmp;

		switch (in) {

		case 'P':
		case 'p':


			printf("\n");
			printf("For the perimeter of a triangle-----------------------\n");
			printf("\n");
			printf("Enter the height of the triangle\n");
			scanf("%lf", &per_h);
			printf("Enter the base of the triangle\n");
			scanf("%lf", &per_b);
			double perim = perimeter_triangle(per_h, per_b);

			if (per_h < 0 || per_b < 0) {

				printf("Error: Height and Base cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The perimeter of a triangle with %lf height and %lf base is %lf\n", per_h, per_b, perim);
				printf("------------------------------------------------------\n");
			}

			break;

		case 'H':
		case 'h':


			printf("\n");
			printf("For the hypotenuse of a triangle-------------------\n");
			printf("\n");
			printf("Enter the height of the triangle:\n");
			scanf("%lf", &hype_h);
			printf("Enter the base of the triangle\n");
			scanf("%lf", &hype_b);
			double hype = hypotenuse(hype_h, hype_b);

			if (hype_h < 0 || hype_b < 0) {

				printf("Error: Height and base cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The hypotenuse of a triangle with %lf height and %lf base is %lf\n", hype_h, hype_b, hype);
				printf("---------------------------------------------------\n");
			}

			break;

		case 'A':
		case 'a':


			printf("\n");
			printf("For the area of a triangle-------------------------\n");
			printf("\n");
			printf("Enter the height of the triangle:\n");
			scanf("%lf", &ht);
			printf("Enter the size of the base:\n");
			scanf("%lf", &bt);
			double at = area_triangle(ht, bt);

			if (ht < 0 || bt < 0) {

				printf("Error: Height and Base cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The area of a triangle with %lf height and %lf base is %lf\n", ht, bt, at);
				printf("\n");
				printf("-----------------------------------------------------------------\n");
			}

			break;

		default:
			printf("\n");
			printf("%c is not an option.\n", in);
			printf("(•_•)\n");
			printf("( •_•)>⌐■-■\n");
			printf("(⌐■_■)\n");
			printf("Later nerd \n");
			printf("\n");
			return 2;

		}

		break;

	case 'C':
	case 'c':

		printf("\n");
		printf("------------------------ Circle Calculations --------------------\n");

		printf("Indicate the calculation you want\n");
		printf("C for circumference\n");
		printf("A for area\n");
		printf("\n");

		while ((tmp = getchar()) != '\n')
		in = tmp;

		switch (in) {

		case 'C':
		case 'c':


			printf("\n");
			printf("For the circumference of a circle------------------\n");
			printf("\n");
			printf("Enter the radius of the circle:\n");
			scanf("%lf", &cr);
			double cc = circumference(cr);

			if (cr < 0) {

				printf("Error: Radius cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The circumference of a circle with %lf radius is %lf\n", cr, cc);
				printf("---------------------------------------------------\n");
			}

			break;

		case 'A':
		case 'a':


			printf("\n");
			printf("For the area of a circle---------------------------\n");
			printf("\n");
			printf("Enter the radius of the circle:\n");
			scanf("%lf", &r);
			double ac = area_circle(r);

			if (ac < 0) {

				printf("Error: Radius cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The area of a circle with radius %lf is %lf\n", r, ac);
				printf("\n");
				printf("-----------------------------------------------------------------\n");
			}

			break;

		default:
			printf("\n");
			printf("%c is not an option.\n", in);
			printf("(•_•)\n");
			printf("( •_•)>⌐■-■\n");
			printf("(⌐■_■)\n");
			printf("Later nerd \n");
			printf("\n");
			return 2;

		}

		break;

	case 'R':
	case 'r':

		printf("\n");
		printf("-------------------- Rectangle Calculations ---------------------\n");

		printf("Indicate the calculation you want to perform\n");
		printf("D for diagonal\n");
		printf("P for perimeter\n");
		printf("A for area\n");
		printf("\n");

		while ((tmp = getchar()) != '\n')
		in = tmp;

		switch (in) {

		case 'D':
		case 'd':


			printf("\n");
			printf("For the diagonal of a rectangle--------------------\n");
			printf("\n");
			printf("Enter the length of the rectangle:\n");
			scanf("%lf", &dl);
			printf("Enter the width of the rectangle\n");
			scanf("%lf", &dw);
			double dr = diagonal_rectangle(dl, dw);

			if (dr < 0 || dw < 0) {

				printf("Error: Length and width cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The diagonal of a rectangle of %lf width and %lf length is %lf\n", dw, dl, dr);
				printf("---------------------------------------------------\n");
			}

			break;

		case 'P':
		case 'p':


			printf("\n");
			printf("For the perimeter of a rectangle-------------------\n");
			printf("\n");
			printf("Enter the length of the rectangle:\n");
			scanf("%lf", &pl);
			printf("Enter the width of the rectangle:\n");
			scanf("%lf", &pw);
			double pr = perimeter_rectangle(pl, pw);

			if (pl < 0 || pw < 0) {

				printf("Error: Length and width cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {
				printf("The perimeter of a rectangle of %lf length and %lf width is %lf\n", pl, pw, pr);
				printf("----------------------------------------------------\n");
			}

			break;

		case 'A':
		case 'a':


			printf("\n");
			printf("For the area of a rectangle-------------------------\n");
			printf("\n");
			printf("Enter the length of the rectangle:\n");
			scanf("%lf", &al);
			printf("Enter the width of the rectangle:\n");
			scanf("%lf", &aw);
			double ar = area_rectangle(al, aw);

			if (al < 0 || aw < 0) {

				printf("Error: Length and width cannot be negative\n");
				printf("(•_•)\n");
				printf("( •_•)>⌐■-■\n");
				printf("(⌐■_■)\n");
				printf("Later nerd \n");
				printf("\n");
				return 2;


			} else {

				printf("The area of a rectangle of %lf lenght and %lf with is %lf\n", al, aw, ar);
				printf("\n");
				printf("-----------------------------------------------------------------\n");
				printf("\n");
			}

			break;

		default:
			printf("\n");
			printf("%c is not an option.\n", in);
			printf("(•_•)\n");
			printf("( •_•)>⌐■-■\n");
			printf("(⌐■_■)\n");
			printf("Later nerd \n");
			printf("\n");
			return 2;

		}

		break;

	default:

		printf("%c is not an option\n", in);
		printf("(•_•)\n");
		printf("( •_•)>⌐■-■\n");
		printf("(⌐■_■)\n");
		printf("Laters nerd \n");
		return 2;
	}

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
	double result = 180 * (ni - 2);
	return result/ni;

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

/**
 * @file lab4_q3.cs
 *
 * @author Julian Garia
 *
 * @date 10/12/2018
 *
 * Assignment: Lab 4
 *
 * @brief Calculates Euclidean distance and Manhattand distance.
 *
 * @details User enters two points to find either Euclidean or Manhattan distance, or both at once.
 *
 * @bugs none
 *
 */



#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct point2d_t
{
	double x1;
	double y1;
	double x2;
	double y2;
	int operation;
	double e_distance;
	double m_distance;
};


double Eu_distance(struct point2d_t point2d);
double Man_distance(struct point2d_t point2d);

int main()
{
	struct point2d_t point2d;

	printf("Enter x1;");
	scanf("%lf", &point2d.x1);
	printf("Enter x2;");
	scanf("%lf", &point2d.x2);
	printf("Enter y1;");
	scanf("%lf", &point2d.y1);
	printf("Enter y2;");
	scanf("%lf", &point2d.y2);



	printf("Choose calculation:\n");
	printf("1 for Euclidean distance\n");
	printf("2 for Manhattan Distance\n");
	printf("3 for both\n");
	scanf("%d", &point2d.operation);
	if (point2d.operation == 1) {
		point2d.e_distance = Eu_distance(point2d);
		printf("Euclidean distance is %lf\n", point2d.e_distance);

	} else if (point2d.operation == 2) {
		point2d.m_distance = Man_distance(point2d);
		printf("Manhattan distance is %lf\n", point2d.m_distance);

	} else if (point2d.operation == 3) {
		point2d.e_distance = Eu_distance(point2d);
		point2d.m_distance = Man_distance(point2d);
		printf("Euclidean distance is %lf\n", point2d.e_distance);
		printf("Manhattan distance is %lf\n", point2d.m_distance);

	} else {
		printf("That is not an option!");

	}

	return 0;
}


double Eu_distance(struct point2d_t point2d)
{

	return sqrt(pow((point2d.x1 - point2d.x2), 2) + pow((point2d.y1 - point2d.y2), 2));
}

double Man_distance(struct point2d_t point2d)
{
	double a = point2d.x1 - point2d.x2;
	double b = point2d.y1 - point2d.y2;

	return abs(a) + abs(b);

}

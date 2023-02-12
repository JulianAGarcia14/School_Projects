#include <stdio.h>
#include <math.h>

float price(float tcost, float pcost, float ticket, float attendees);

int main(void)
{
	float tcost = 20;
	float pcost = 0.2;
	float ticket = 5;
	float attendees;

	float profit = price(tcost, pcost, ticket, attendees);

	printf("The profit of the show is %lf\n", profit);

}

float price(tcost, pcost, ticket, attendees)
{

return (ticket*attendees) - (pcost*attendees) - tcost;

}

#include <stdio.h>
#include <math.h>

int sumcoins(pennies, dimes, quarters, nickels);


int main(void)
{

	int pennies;
	int dimes;
	int quarters;
	int nickels;
	printf("Number of pennies %f\n", pennies);
	printf("Number of dimes %f\n", dimes);
	printf("Number of quarters %f\n", quarters);
	printf("Number of nickels %f\n", nickels);



	int sum = sumcoins(pennies, dimes, quarters, nickels);
	printf("Sum of coins equals %f\n", sum);

	return 0;

}

int sumcoins(pennies, dimes, quarters, nickels)
{

	return pennies + (dimes*10) + (quarters*25) + (nickels*5);
}

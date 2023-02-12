#include <stdio.h>

float work(float wage, float hours);
float netpay(float salary);

int main(void)
{
	float wage = 12;
	float hours = 70;
	float bwage = 12*1.5;
	float overtime;

	if (hours > 40) {
		overtime = hours - 40;
	} else {
		overtime = 0;
	}

	float salary = work(wage, hours) + work(bwage, overtime);

	printf("Salary = $%lf", salary);

	float netpay = salary - netpay(salary);
	printf("Netpay = $%lf", netpay);

	return 0;

}

float netpay(float salary)
{
	return salary*0.15;

}

float work(float wage, float hours)
{

	return wage*hours;
}

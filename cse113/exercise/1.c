#include <stdio.h>

int max(int num1, int num2);

int main(void)
{
	int num1;
	int num2;



}

int max(int num1, int num2)
{
	if (num1 > num2) {
		return num1;
	}else {
		return num2;
	}

	return (num1 > num2) ? num1 , num2;
}

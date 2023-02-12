#include <stdio.h>

int BinaryToDecimal(int x);

int main()
{
	int x;
	int y;
	printf("Enter binary value to convert to decimal\n");
	scanf("%d", &x);
	y = BinaryToDecimal(x);
	printf("Decimal value of %d is : %d\n", x, y);

	return 0;
}

int BinaryToDecimal(int x)
{
	int value = 1;
	int temp;
	int sum = 0;
	while(x)
	{
		temp = x % 10;
		if(temp == 1){
			sum = sum + value;
		}
		x /= 10;
		value = value * 2;
	}
	return sum;

}

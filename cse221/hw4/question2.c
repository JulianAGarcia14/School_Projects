#include <stdio.h>

int main()
{
	int n, c, k, value, i;

  	printf("Enter decimal value to convert to binary\n");
  	scanf("%d", &n);

  	printf("%d in binary is:\n", n);
	value = 1;
	i = -1;
	while(value < n)
	{
		value = value * 2;
		i = i + 1;
	}

  	for (c = i; c >= 0; c--)
  	{
    		k = n >> c;

    		if (k & 1)
      			printf("1");
    		else
      			printf("0");
  	}

  	printf("\n");

  	return 0;
}

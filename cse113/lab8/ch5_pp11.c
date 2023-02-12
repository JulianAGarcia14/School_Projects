#include<stdio.h>

int main()
{
	int area_code;

	printf("Enter the area code for lookup\n");
	scanf("%d", &area_code);

	switch (area_code) {

	case 229:
		printf("Albany\n");
		break;

	case 404:
		printf("Atlanta\n");
		break;

	case 470:
		printf("Atlanta\n");
		break;

	case 478:
		printf("Macon\n");
		break;

	case 678:
		printf("Atlanta\n");
		break;

	case 706:
		printf("Colombus\n");
		break;

	case 762:
		printf("Colombus\n");
		break;

	case 770:
		printf("Atlanta\n");
		break;

	case 912:
		printf("Savannah\n");
		break;

	default:

		printf("Area code not recognized\n");
		return 2;


	}

	return 0;
}

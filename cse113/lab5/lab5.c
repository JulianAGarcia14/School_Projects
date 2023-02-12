/**
* @file lab5.c
*
* @author Julian Garcia
*
* @date 3/8/2018
*
* Assignment: Lab 5
*
* @brief contains main function for zombie.
*
* @details Creates a log for zombie encounters
*
* @bugs none
*
* @todo none
*/

#include <stdio.h>
#include "zombie.h"



int main(void)
{
	int info;
	char strg[2];
	struct zombie_t zombies[SIZE];
	int i = 0;

	while (info != 3) {
		printf("1) Enter new zombie info\n");
		printf("2) Display zombie info\n");
		printf("3) Get back at it (leave)\n\n");
		fgets(strg, sizeof(strg), stdin);
		sscanf(strg ,"%d", &info);

		switch(info) {
			case 1:
				dead(i, zombies);
				input_time(i, zombies);
				switch(zombies[i].dead) {
					case 'n':
						zombies[i].blood = input_blood();
						break;

					case 'y':
						zombies[i].toes = input_toes();
						break;
					}

					i = i + 1;

					if (i % 5 == 0) {
						i = 0;
					}

				break;
			case 2:
				print_zombies(zombies, SIZE);
				getchar();
				break;
			case 3:
				return 2;
				break;

		}

	}

	return 0;
}

/**
* @file zombie.c
*
* @author Julian Garcia
*
* @date 10/22/2018
*
* Assignment: Lab 5
*
* @brief a program that logs zombie encounters
*
* @details Multiple functions all used to keep record of certain user data.
*
* @bugs none
*
* @todo none
*/

#include "zombie.h"
#include<string.h>
#include <stdio.h>

/** Asks if the zombie was found dead
 * @param i index of record
 * @return 1
 */

int dead(int i, struct zombie_t zombies[])
{
	char str[3];
	printf("Is the zombie dead (y/n)\n");
	getchar();
	fgets(str, sizeof(str), stdin);
	sscanf(str ,"%c", &zombies[i].dead);
	if (zombies[i].dead == 0) {
		printf("Unacceptable input for death of zombie\n");
		return 2;
	}
	return 1;


}

/** Asks for the time the zombie was found
 * @param i index of record
 * @return 1
 */
int input_time(int i, struct zombie_t zombies[])
{

	char str2[2];
	char str3[10];

	printf("Choose the day this zombie was found\n");
	printf("1)Monday\n");
	printf("2)Tuesday\n");
	printf("3)Wednesday\n");
	printf("4)Thursday\n");
	printf("5)Friday\n");
	printf("6)Saturday\n");
	printf("7)Sunday\n");

	fgets(str2, sizeof(str2), stdin);
	sscanf(str2 ,"%u", &zombies[i].day);
	getchar();

	if (zombies[i].day > 7) {
		printf("Unacceptable input for day\n");
		return 2;
	}

	printf("Enter the time of the event\n");
	printf("Separate hours, minutes, and seconds by colons.\n");
	printf("HH:MM:SS\n");
	fgets(str3, sizeof(str3), stdin);
	sscanf(str3 ," %d:%d:%d", &zombies[i].hour, &zombies[i].min, &zombies[i].sec);



	return 1;

}

/** Asks for the number of toes on the zombie
 * @param i index of record
 * @return 1
 */
int input_toes()
{


	char str[4];
	int toes;
	printf("Enter the amount of toes found on the body\n");
	fgets(str, sizeof(str), stdin);
	sscanf(str ,"%d", &toes);
	return toes;

}

/** Asks for the amount of blood the zombie bled
 * @param i index of record
 * @return 1
 */
float input_blood()
{
	char str[7];
	int blood;
	printf("Enter the amount of blood the zombie lost\n");
	fgets(str, sizeof(str), stdin);
	sscanf(str ," %d", &blood);
	return blood;
}

/** Prints the record of zombies fought
 * @param size size of index
 * @return void
 */
void print_zombies(struct zombie_t zombies[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++) {


		switch (zombies[i].dead) {
			case 'y':
				printf("This zombie was found dead\n");
				printf("This zombie had %d toes\n", zombies[i].toes);
				printf("This zombie was sighted ");

				switch (zombies[i].day) {
					case MONDAY:
						printf("Monday ");
						break;
					case TUESDAY:
						printf("Tuesday ");
						break;
					case WEDNESDAY:
						printf("Wednesday ");
						break;
					case THURSDAY:
						printf("Thursday ");
						break;
					case FRIDAY:
						printf("Friday ");
						break;
					case SATURDAY:
						printf("Saturday ");
						break;
					case SUNDAY:
						printf("Sunday ");
						break;

				}

				printf("at %d:%d:%d\n\n", zombies[i].hour, zombies[i].min, zombies[i].sec);
				break;
			case 'n':
				printf("This zombie was found alive\n");
				printf("It lost %fmL of blood when killed\n", zombies[i].blood);
				printf("This zombie was sighted ");
				switch (zombies[i].day) {
					case MONDAY:
						printf("Monday ");
						break;
					case TUESDAY:
						printf("Tuesday ");
						break;
					case WEDNESDAY:
						printf("Wednesday ");
						break;
					case THURSDAY:
						printf("Thursday ");
						break;
					case FRIDAY:
						printf("Friday ");
						break;
					case SATURDAY:
						printf("Saturday ");
						break;
					case SUNDAY:
						printf("Sunday ");
						break;

				}
				printf("at %d:%d:%d\n\n", zombies[i].hour, zombies[i].min, zombies[i].sec);
				break;
			}

	}
}

/**
* @file zombie.h
*
* @author Julian Garcia
*
* @date 10/22/2018
*
* Assignment: Lab 5
*
* @brief Header file for zombie.c
*
* @details Contains function declarations and enumerations
*
* @bugs none
*
* @todo none
*/
#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#define SIZE 5


struct zombie_t {

	enum {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} day;

	float blood;

	int toes;

	int hour;

	int min;

	int sec;

	char dead;
	/*y if dead, n if alive*/
};

int input_time(int i, struct zombie_t zombies[]);
int input_toes();
float input_blood();
void print_zombies(struct zombie_t zombies[], int size);
int dead(int i, struct zombie_t zombies[]);

#endif

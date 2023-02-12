/**
 * @file credit.c
 * @author Julian Garcia
 * @date 2/19/2018
 * @brief determine if a credit card is valid using Luhn's algorithm.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1

void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);
void multiply(int card[], int size);
int sum(int card[], int size);
int validity(int sum);
void print_validity(int val);

int main(void)
{
	int card[NUM_DIGITS];
	char visa[] = "4012888888881881"; /* valid card */
	/*char visa[] = "4012888888881882"; */ /*invalid card */
	int SUM;
	int val;

	convert_card(card, visa, NUM_DIGITS);
	print_card(card, NUM_DIGITS);
	multiply(card, NUM_DIGITS);

	SUM = sum(card, NUM_DIGITS);
	val = validity(SUM);
	print_validity(val);


	return 0;

}

/** Converts the card digits to array values
 * @param card[] the array to have the cards numbered assigned to
 * @param num[] the given card numbers
 * @param num_digits the size of the array
 * @return void
 */
void convert_card(int card[], char num[], int num_digits)
{
	int i;

	for(i = 0; i < num_digits; i++)
		card[i] = num[i] - '0';

}

/** Prints the card number as an array
 * @param card[] the given array
 * @param size the size of the array
 * @return void
 */
void print_card(int card[], int size)
{
	int i;
	printf("\nOriginal series\n");

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

/** Doubles every other number of the card
 * @param card[] the given array
 * @param size the size of the array
 * @return void
 */
void multiply(int card[], int size)
{
	int i;
	printf("\n Series after doubling is\n");

	for (i = 0; i < size; i++)
		if (i % 2 == 0) {

			card[i] = card[i] * 2;
			printf("card[%d] = %d\n", i, card[i]);

		} else {
			printf("card[%d] = %d\n", i, card[i]);

		}


}

/** Sums all the numbers of the card, and splits two digit numbers
 * @param card[] the given array
 * @param size the size of the array
 * @return void
 */
int sum(int card[], int size)
{
	int i;
	int sum = 0;
	int sum_1 = 0;
	int sum_2 = 0;

	for (i = 0; i < size; i++)
		if (card[i] > 9) {
			sum_1 = sum_1 + (card[i] / 10) + (card[i] % 10);
		} else {
			sum_2 = card[i] + sum_2;
		}
	sum = sum_1 + sum_2;
	printf("\nsum is %d\n", sum);
	return sum;
}

/** Checks if the card is valid
 * @param sum the sum of the card numbers
 * @return Valid or invalid
 */
int validity(int sum)
{
	if (sum % 10 == 0) {
		return VALID;
	} else {
		return INVALID;
	}

}

/** Prints whether or not the card was valid
 * @param val the validity value
 * @return void
 */
void print_validity(int val)
{
	if (val == VALID) {
		printf("Card is valid\n");
	} else {
		printf("Card is invalid\n");
	}

}

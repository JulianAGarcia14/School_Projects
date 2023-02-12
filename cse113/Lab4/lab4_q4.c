/**
 * @file lab4_q4.c
 *
 * @author Julian Garia
 *
 * @date 10/12/2018
 *
 * Assignment: Lab 4
 *
 * @brief Question 4 of lab4, finds zodiac sign
 *
 * @details Uses user input to find zodiac sign
 *
 * @bugs none
 *
 */



#include<stdio.h>

#define ERROR 4004
#define LEAP 3003
#define NOT 2002

enum month
{
	JAN = 1, FEB, MAR, APR, MAY, JUNE, JUL, AUG, SEPT, OCT, NOV, DEC
};

enum sign
{
	SAG = 13, CAP, AQUA, PISCES, ARIES, TAURUS, GEM, CANCER, LEO, VIRGO, LIBRA, SCORP
};

unsigned short find_day(unsigned short month, unsigned short leap_year);
unsigned short find_zodiac(unsigned short month, unsigned short day, unsigned short year);
void print_zodiac(unsigned short zodiac);
unsigned short find_leapyear(unsigned short year);

int main(void)
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
	unsigned short zodiac;
	unsigned short leapyear;


        while (month != 13) {
		printf("\n\n");
		printf("Enter the number of the month (1-12):\n");
		printf("Enter 13 to exit\n");
		printf("Month: ");
		scanf("%hu", &month);

		if (month > 13 || month < 1) {
			printf("That is not an option!\n");
			return 2;
		} else if (month == 13) {

			return 2;
		}

		printf("Enter the year:\n");
		printf("Year: ");
		scanf("%hu", &year);
		if (year < 1) {
			printf("That is not an option!\n");
			return 2;
		}

		leapyear = find_leapyear(year);

		day = find_day(month, leapyear);
		if (day == ERROR) {
			printf("\n");
			return 2;
		}

		zodiac = find_zodiac(month, day, year);
		print_zodiac(zodiac);



	}

	return 0;

}

/** Finds out whether or not the year is a leap year
 * @param year the given year
 * @return if the year is a leap year
 */
unsigned short find_leapyear(unsigned short year)
{
	int leapyear;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {

		leapyear = LEAP;
	} else {
		leapyear = NOT;
	}

	return leapyear;
}

/** Prints out the found zodiac sign
 * @param zodiac value which represents the found zodiac sign
 * @return void
 */
void print_zodiac(unsigned short zodiac)
{
	switch(zodiac) {
		case CAP:
			printf("Your sign is Capricorn");
			break;
		case SAG:
			printf("Your sign is Sagittarius");
			break;
		case AQUA:
			printf("Your sign is Aquarius");
			break;
		case PISCES:
			printf("Your sign is Pisces");
			break;
		case ARIES:
			printf("Your sign is Aries");
			break;
		case TAURUS:
			printf("Your sign is Taurus");
			break;
		case GEM:
			printf("Your sign is Gemini");
			break;
		case CANCER:
			printf("Your sign is Cancer");
			break;
		case LEO:
			printf("Your sign is Leo");
			break;
		case VIRGO:
			printf("Your sign is Virgo");
			break;
		case LIBRA:
			printf("Your sign is Libra");
			break;
		case SCORP:
			printf("Your sign is Scorpio");
			break;


	}

}

/** Finds zodiac sign
 * @param month the given month
 * @param day the given day
 * @param year the given year
 * @return sign the zodiac sign
 */
unsigned short find_zodiac(unsigned short month, unsigned short day, unsigned short year)
{
	unsigned short sign;

	switch(month) {
	case JAN:
		if (day <= 20) {
			sign = CAP;
		} else {
			sign = AQUA;
		}
		break;
	case FEB:
		if (day <= 19) {
			sign = AQUA;
		} else {
			sign = PISCES;
		}
		break;
	case MAR:
		if (day <= 20) {
			sign = PISCES;
		} else {
			sign = ARIES;
		}
		break;
	case APR:
		if (day <= 20) {
			sign = ARIES;
		} else {
			sign = TAURUS;
		}
		break;
	case MAY:
		if (day <= 21) {
			sign = TAURUS;
		} else {
			sign = GEM;
		}
		break;
	case JUNE:
		if (day <= 21) {
			sign = GEM;
		} else {
			sign = CANCER;
		}
		break;
	case JUL:
		if (day <= 22) {
			sign = CANCER;
		} else {
			sign = LEO;
		}
		break;

	case AUG:
		if (day <= 22) {
			sign = LEO;
		} else {
			sign = VIRGO;
		}
		break;
	case SEPT:
		if (day <= 23) {
			sign = VIRGO;
		} else {
			sign = LIBRA;
		}
		break;
	case OCT:
		if (day <= 23) {
			sign = LIBRA;
		} else {
			sign = SCORP;
		}
		break;
	case NOV:
		if (day <= 22) {
			sign = SCORP;
		} else {
			sign = SAG;
		}
		break;
	case DEC:
		if (day <= 21) {
			sign = SAG;
		} else {
			sign = CAP;
		}
		break;


	}

	return sign;

}

/** Determines the date, and whether or not it's valid
 * @param month the given month
 * @param leap_year whether or not the year is a leap year
 * @return day the found day
 */
unsigned short find_day(unsigned short month, unsigned short leap_year)
{
	unsigned short day;
	int feb_max;

	switch(month) {
	case JAN:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 31 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
 		} else {

			return day;
		}
		break;
	case FEB:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);
		if (leap_year == LEAP) {
			feb_max = 29;
		} else if (leap_year == NOT) {
			feb_max = 28;
		}

		if (day > feb_max || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case MAR:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 31 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case APR:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 30 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case MAY:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 31 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
			}
		break;
	case JUNE:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 30 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case JUL:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 31 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;

	case AUG:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 31 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case SEPT:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 30 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case OCT:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 31 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case NOV:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 30 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;
	case DEC:
		printf("Enter the day:\n");
		printf("Day: ");
		scanf("%hu", &day);

		if (day > 31 || day < 1) {
			printf("Error: That is not a day of the month!");
			return ERROR;
		} else {

			return day;
		}
		break;


	}
	return 1;

}

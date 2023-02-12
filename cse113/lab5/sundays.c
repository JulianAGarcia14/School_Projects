/**
* @file Sundays.c
*
* @author Julian Garcia
*
* @date 10/22/2018
*
* Assignment: Lab 5
*
* @brief a program that counts sundays
*
* @details Counts sundays up to a certain date
*
* @bugs none
*
* @todo none
*/

#include <stdio.h>

#define LEAP 1001
#define NOT 40004

int leap(int year);

int main(void)
{
	int day = 1;
	int sumofdays = 0;
	int sundays;
	for (int year = 1900; year <= 2000; year++) {
		int leapyear = leap(year);
    		for (int month = 1; month <= 12; month++) {
			if (month == 1) {
				while (day != 32) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 2) {
				if (leapyear == LEAP) {
					while (day != 30) {
						day = day + 1;
					}
				} else if (leapyear == NOT) {
					while (day != 29) {
						day = day + 1;
					}
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 3) {
				while (day != 32) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 4) {
				while (day != 31) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 5) {
				while (day != 32) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 6) {
				while (day != 31) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 7) {
				while (day != 32) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 8) {
				while (day != 32) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 9) {
				while (day != 31) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 10) {
				while (day != 32) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 11) {
				while (day != 31) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			} else if (month == 12) {
				while (day != 32) {
					day = day + 1;
				}
				sumofdays = sumofdays + day;
				day = 1;
			}
		}
	}
	sumofdays = sumofdays - 48; /*Number of sundays in 1900*/
	sundays = sumofdays / 7;
	printf("Number of sundays between 1901 and 2000 is %d\n", sundays);
	return 0;
}

int leap(int year) {

	int leapyear;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		leapyear = LEAP;
	} else {
		leapyear = NOT;
	}
	return leapyear;
}

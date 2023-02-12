/**
 * @file array.h
 *
 * @author Julian Garcia
 *
 * @date 10/1/2018
 *
 * Assignment: Lab 3
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *
 * @bugs none
 *
 * @todo add floating point versions of the functions
 */


#ifndef KML_H_
#define KML_H_

#include <stdlib.h>
#define LEN 48

struct geo_city_t {
	char *city;
	char *state;
	/* 2 char postal code */
	char *country;
	float latitude;
	float longitude;
};

struct data_t {
	int nval;
	/* current number of values in array */
	int max;
	/* allocated number of values */
	struct geo_city_t *data;
	/* the data array */
};


enum {INIT = 1, GROW = 2};


/*void kmlbegin();
void kmlplacemark();
void kmlend();

void setcitystatecountry();
void setlatitude();
void setlongitude();
*/
#endif

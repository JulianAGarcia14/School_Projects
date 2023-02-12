/**
 * @file kml.h
 *
 * @author Julian Garcia
 *
 * @date 1/24/2019
 *
 * Assignment: Lab 11
 *
 * @brief header file for lab11.c
 *
 * @details see lab11.c for details
 *
 * @bugs none
 *
 * @todo add floating point versions of the functions
 */


#ifndef KML_H_
#define KML_H_

#include <stdlib.h>
#define LEN 128

struct geo_city_t {
	char *city;
	char *state;
	/* 2 char postal code */
	char *country;
	float latitude;
	float latitude_deg;
	float longitude;
	float longitude_deg;
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

unsigned int my_strlen(char *p);
/*void kmlbegin();
void kmlplacemark();
void kmlend();
*/

void setcitystatecountry(struct data_t *data, char buf[LEN], int i);
void setlatitude(int i, struct data_t *data, char buf[LEN]);
void setlongitude(int i, struct data_t *data, char buf[LEN]);

#endif

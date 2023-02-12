/**
 * @file kml.c
 *
 * @author Julian Garcia
 *
 * @date 1/24/2019
 *
 * Assignment: Lab 11
 *
 * @brief contains functions for lab11.c
 *
 * @details functions process file stream input into kml versions
 *
 * @bugs none
 *
 * @todo
 */


#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "kml.h"

/** Finds string length of current line
 * @param p string to be parsed
 * @return count of string
 */
unsigned int my_strlen(char *p)
{
    unsigned int count = 0;

    while(*p!='\n')
    {
        count++;
        p++;
    }

    return count;
}

/** Inserts kml document header
 * @return void
 */
void kmlbegin(struct data_t *data, int i)
{

	FILE *out2 = fopen("locations.kml", "w");
	fprintf(out2, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(out2, "<kml xmlns=\"http://earth.google.com/kml/2.1\">\n");
	fprintf(out2, "<Document>\n");
	fprintf(out2, "<name>Mystery Locations</name>\n");

	kmlplacemark(data, out2, i);

}

/** Inserts kml locations
 * @param out2 file to be written to
 * @return void
 */
void kmlplacemark(struct data_t *data, FILE *out2, int i)
{
	int k;
	int j;
	float min = 60;
	float holder;
	for (k = 0; k <= i ; k++) {
		data->data[k].latitude_min = data->data[k].latitude_deg * min;
		data->data[k].latitude_sec = modff(data->data[k].latitude_min, &holder);
		data->data[k].latitude_min = holder;
		data->data[k].latitude_sec = data->data[k].latitude_sec * 60;
		data->data[k].latitude_deg = data->data[k].latitude_deg + (data->data[k].latitude_min / 60) + (data->data[k].latitude_sec / 360);

		data->data[k].longitude_min = data->data[k].longitude_deg * min;
		data->data[k].longitude_sec = modff(data->data[k].longitude_min, &holder);
		data->data[k].longitude_min = holder;
		data->data[k].longitude_sec = data->data[k].longitude_sec * 60;
		data->data[k].longitude_deg = data->data[k].longitude_deg + (data->data[k].longitude_min / 60) + (data->data[k].longitude_sec / 360);
	}
	for (j = 0; j <= i; j++) {
		fprintf(out2, "<Placemark>\n");
		fprintf(out2, "<name>Location %d</name>\n", j + 1);
		fprintf(out2, "<Point>\n");
		fprintf(out2, "<coordinates>-%lf,%lf,0</coordinates>\n", data->data[j].latitude_deg, data->data[j].longitude_deg);
		fprintf(out2, "</Point>\n");
		fprintf(out2, "</Placemark>\n");

	}


	kmlend(out2);
}

/** Inserts Kml document footer
 * @return void
 */
void kmlend(FILE *out2)
{

	fprintf(out2, "</Document>\n");
	fprintf(out2, "</kml>\n");
	fclose(out2);
}


/** Parses location into structure array
 * @param data, structure to be used
 * @param buf, current line from the file stream
 * @return void
 */
int setcitystatecountry(struct data_t *data, char buf[LEN], FILE *in)
{
	int loc = 0;
	int i = 0;
	int c_loc = 0;
	int lat = 0;
	int lon = 0;
	int ll;
	char *p;
	char *s;
	char *us = "United States";
	size_t uslength = strlen(us);
	int length;
	unsigned char ch = ',';


	while (fgets(buf, LEN, in)) {
		if (data->nval > data->max) {
			data->data = realloc(data->data, GROW * data->max *sizeof(struct geo_city_t));
			data->max = GROW * data->max;
		} else if (data->data == NULL) {
			data->data = malloc(INIT * sizeof(struct geo_city_t));
		}
		if(i == 0){
		} else {


			p = strchr(buf, ch);


			if (p != NULL){
				length = my_strlen(p);

				if(length - 2 == 2) {

					data->data[loc].state = malloc(length * sizeof(char*));
					strncpy(data->data[loc].state, p, length);
					data->data[loc].country = malloc(uslength * sizeof(char*));
					strncpy(data->data[loc].country, us, uslength);
					loc++;
				} else {
					data->data[loc].country = malloc(length * sizeof(char*));
					strncpy(data->data[loc].country, p, length);
					loc++;
				}
				s = strtok(buf, ",");
				length = my_strlen(s);
				data->data[c_loc].city = malloc(length * sizeof(char*));
				strncpy(data->data[c_loc].city, s, length);
				c_loc++;


			} else {

				ll = setlatitude(lat, lon, data, buf);
				if (ll == 1) {
					lat++;
				}else {
					lon++;
				}


			}

		}
		i++;
		data->nval++;
	}

	int j = 0;
	for(j = 0; j <= i; j++){

		free(data->data[j].city);
		free(data->data[j].state);
		free(data->data[j].country);
	}

	free(data->data);
	
	return lat;
}

void print_normal(int lat, struct data_t *data, char buf[LEN])
{
	int k;
	FILE *out = fopen("location.out", "w");

	if (!out) {
		printf("Could not open file for writing\n");

	}

	for (k = 0; k < lat; k++){

		fprintf(out, "(city = %s, state = %s, country = %s, latitude = %lf & %lf N/S, longitude = %lf & %lf E/W. )\n"
		, data->data[k].city, data->data[k].state, data->data[k].country,
		data->data[k].latitude, data->data[k].latitude_deg, data->data[k].longitude,
		data->data[k].longitude_deg);

	}
	fclose(out);
}

/** Places latitude information into structure
 * @return void
 */
int setlatitude(int lat, int lon, struct data_t *data, char buf[LEN])
{
	char *p;
	char *s;
	int num;
	p = strchr(buf, 'N');
	if (p != NULL) {
		s = strtok(buf, " ");
		data->data[lat].latitude = atof(s);
		s = strtok(NULL, "\n");
		data->data[lat].latitude_deg = atof(s);
		num = 1;
	} else {
		num = setlongitude(lon, data, buf);
	}
	return num;

}

/** Places latitude information into structure
 * @return void
 */
int setlongitude(int i, struct data_t *data, char buf[LEN])
{
	char *p;
	char *s;
	p = strchr(buf, 'W');
	if (p != NULL) {
		s = strtok(buf, " ");
		data->data[i].longitude = atof(s);
		s = strtok(NULL, "\n");
		data->data[i].longitude_deg = atof(s);
	}

	return 3;

}

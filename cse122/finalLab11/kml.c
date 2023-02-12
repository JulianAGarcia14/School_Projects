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


/*void kmlbegin()
{


}

void kmlplacemark()
{

}

void kmlend()
{


}
*/

/** Parses location into structure array
 * @param data, structure to be used
 * @param buf, current line from the file stream
 * @return void
 */
void setcitystatecountry(struct data_t *data, char buf[LEN], int i)
{

	char *p;
	char *s;
	char *us = "United States";
	size_t uslength = strlen(us);
	int length;
	unsigned char ch = ',';



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
				printf(" yo %s %d\n", p, length);
				if(length - 2 == 2) {

					data->data[i].state = malloc(length * sizeof(char*));
					strncpy(data->data[i].state, p, length);
					data->data[i].country = malloc(uslength * sizeof(char*));
					strncpy(data->data[i].country, us, uslength);

				} else {
					data->data[i].country = malloc(length * sizeof(char*));
					strncpy(data->data[i].country, p, length);

				}
				s = strtok(buf, ",");
				length = my_strlen(s);
				data->data[i].city = malloc(length * sizeof(char*));
				strncpy(data->data[i].city, s, length);
				

			} else {
				setlatitude(i, data, buf);
				setlongitude(i, data, buf);

			}

		}


	free(p);
	free(s);

}

/** Places latitude information into structure
 * @return void
 */
void setlatitude(int i, struct data_t *data, char buf[LEN])
{
	char *p;
	char *s;
	p = strchr(buf, 'N');
	if (p != NULL) {
		s = strtok(buf, " ");
		data->data[i].latitude = atof(s);
		s = strtok(NULL, "\n");
		data->data[i].latitude_deg = atof(s);
	}

}

/** Places latitude information into structure
 * @return void
 */
void setlongitude(int i, struct data_t *data, char buf[LEN])
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

}

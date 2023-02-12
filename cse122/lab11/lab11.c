#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include "kml.h"


void print_points(struct geo_city_t *cities, int num_points)
{
	int i;
	for (i = 0; i < num_points; i++)
	printf("(city = %s, state = %s, country = %s, latitude = %lf, longitude = %lf. )\n", cities[i].city, cities[i].state, cities[i].country, cities[i].latitude, cities[i].longitude);
}



int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: points filename\n");
		return -1;
	}
	int num_points;
	size_t length;
	char buf[LEN];
	int i = 0;
	FILE *in = fopen(argv[1], "r");
	char *p;
	char *s;
	char *d;
	char *la;
	char *lo;
	char *us = "United States";
	size_t uslength = strlen(us);
	struct data_t *data = malloc(sizeof(struct data_t));
	data->nval = INIT;
	data->max = INIT;
	data->data = NULL;

	while (fgets(buf, LEN, in)) {
		if (data->nval > data->max) {
			data->data = realloc(data->data, GROW * data->max *sizeof(struct geo_city_t));
			data->max = GROW * data->max;
		} else if (data->data == NULL)
		data->data = malloc(INIT * sizeof(struct geo_city_t));

		if(i < 4){
		} else
			p = strchr(buf, ',');
			s = strtok(buf, ",");
			//p = strtok(buf, ",");


			length = strlen(p);
			if(length - 1 == 2) {
				//data->data[i].state = s;
				data->data[i].state = malloc(length * sizeof(char*));
				strncpy(data->data[i].state, p, length);
				data->data[i].country = malloc(uslength * sizeof(char*));
				strncpy(data->data[i].state, p, length);
				//data->data[i].country = us;
			} else {
				data->data[i].country = malloc(length * sizeof(char*));
				strncpy(data->data[i].country, p, length);
				//data ->data[i].country = s;
			}
			//*p = '\0';

			length = strlen(s);
			data->data[i].city = malloc(length * sizeof(char*));
			strncpy(data->data[i].city, s, length);
			//data->data[i].city = s;

	/*	p = strchr(buf, ',');
	//	d = strchr(p, ' ');
		length = strlen(p);//strlen(s);
		if(length - 1 == 2) {
			//data->data[i].state = s;
			data->data[i].state = malloc(length * sizeof(char*));
			strncpy(data->data[i].state, p, length);
			data->data[i].country = malloc(uslength * sizeof(char*));
			strncpy(data->data[i].state, p, length);
			//data->data[i].country = us;
		} else {
			data->data[i].country = malloc(length * sizeof(char*));
			strncpy(data->data[i].country, p, length);
			//data ->data[i].country = s;
		}
		//*p = '\0';

		/*if(i == 0){
			s = strtok(buf, "");
			s = strtok(NULL, "");
			s = strtok(NULL, "");
			s = strtok(NULL, "");
		//	p = strchr(NULL, ",");
		} else if(i > 0) {
			s = strtok(buf, "");
			//p = strtok(buf, ",");
		}
		s = strtok(buf, ","),
		length = strlen(s);
		data->data[i].city = malloc(length * sizeof(char*));
		strncpy(data->data[i].city, s, length);
		//data->data[i].city = s;

		la = strtok(NULL, "N");
		data->data[i].latitude = atof(la);

		lo = strtok(NULL, "W");
		data->data[i].longitude = 45;//atof(lo);
		*/
		i++;
		data->nval++;
	}

	print_points(data->data, i);

	fclose(in);
	int j = 0;
	for(j = 0; j <= i; j++){

		free(data->data[j].city);
		free(data->data[j].state);
		free(data->data[j].country);
	}
	free(data->data);
	free(data);

	return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "kml.h"


void print_points(struct geo_city_t *cities, int num_points)
{
	int i;
	for (i = 0; i < num_points; i++)
	printf("(city = %s, state = %s, country = %s, latitude = %lf, longitude = %lf. )\n", cities[i].city, cities[i].state, cities[i].country, cities[i].latitude, cities[i].longitude);
}


unsigned int my_strlen(char *p)
{
    unsigned int count = 0;

    while(*p!='\n')//||*p!='\0')
    {
        count++;
        p++;
    }

    return count;
}


int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: points filename\n");
		return -1;
	}
	int num_points;
	//size_t length;
	char buf[LEN];
	int i = 0;
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen("location", "w");
	if (!out) {
		printf("Could not open file for writing\n");
		return -1;
	}

	char *p;
	char *s;


	char *us = "United States";
	size_t uslength = strlen(us);
	int length;
	struct data_t *data = malloc(sizeof(struct data_t));
	data->nval = INIT;
	data->max = INIT;
	data->data = NULL;
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
			//p = strtok(buf, ",");

			if (p != NULL){
				length = my_strlen(p);
				printf(" yo %s %d\n", p, length);
				if(length - 2 == 2) {
					//data->data[i].state = s;
					data->data[i].state = malloc(length * sizeof(char*));
					strncpy(data->data[i].state, p, length);
					data->data[i].country = malloc(uslength * sizeof(char*));
					strncpy(data->data[i].country, us, uslength);
					//data->data[i].country = us;
				} else {
					data->data[i].country = malloc(length * sizeof(char*));
					strncpy(data->data[i].country, p, length);
					//data->data[i].country = p;
					//data ->data[i].country = s;
				}
				//*p = '\0';
				s = strtok(buf, ",");
				length = my_strlen(s);
				data->data[i].city = malloc(length * sizeof(char*));
				strncpy(data->data[i].city, s, length);
				//data->data[i].city = s;
			} else {
				p = strchr(buf, 'N');
				if (p != NULL) {
					s = strtok(buf, "\n");
					printf("Yo %s\n", s);
					data->data[i].latitude = atof(s);
				}
				p = strchr(buf, 'W');
				if (p != NULL) {
					s = strtok(buf, "\n");
					printf("Yo %s\n", s);
					data->data[i].longitude = atof(s);
				}
				printf("%lf and %lf\n", data->data[i].latitude, data->data[i].longitude);

			}
				//data->data[i].city = s;

		}
		i++;
		data->nval++;
	}

	//print_points(data->data, i - 3);
	int k;
	for (k = 3; k < i - 1;){

	fprintf(out, "(city = %s, state = %s, country = %s, latitude = %lf, longitude = %lf. )\n", data->data[k].city, data->data[k].state, data->data[k].country, data->data[k + 1].latitude, data->data[k + 2].longitude);
	k = k + 3;
	}


	int j = 0;
	for(j = 0; j <= i; j++){

		free(data->data[j].city);
		free(data->data[j].state);
		free(data->data[j].country);
	}
	free(data->data);
	free(data);
	free(p);
	free(s);
	fclose(in);
	fclose(out);

	return 0;
}

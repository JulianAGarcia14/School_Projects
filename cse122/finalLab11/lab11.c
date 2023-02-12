/**
 * @file lab11.c
 *
 * @author Julian Garcia
 *
 * @date 1/24/2019
 *
 * Assignment: Lab 11
 *
 * @brief contains main function for lab11
 *
 * @details opens file stream and writes file for locations using called functions
 *
 * @bugs none
 *
 * @todo make code more efficient
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "kml.h"


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


	struct data_t *data = malloc(sizeof(struct data_t));
	data->nval = INIT;
	data->max = INIT;
	data->data = NULL;

	while (fgets(buf, LEN, in)) {
		setcitystatecountry(data, buf, i);
		i++;
		data->nval++;
	}
	//print_points(data->data, i - 3);
	int k;
	for (k = 3; k < i - 1;){

	fprintf(out, "(city = %s, state = %s, country = %s, latitude = %lf & %lf, longitude = %lf & %lf. )\n"
	, data->data[k].city, data->data[k].state, data->data[k].country,
	data->data[k + 1].latitude, data->data[k + 1].latitude_deg, data->data[k + 2].longitude,
	data->data[k + 2].longitude_deg);
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
	fclose(in);
	fclose(out);

	return 0;
}

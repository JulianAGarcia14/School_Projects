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
#include<math.h>
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

	char buf[LEN];
	int i;

	FILE *in = fopen(argv[1], "r");




	struct data_t *data = malloc(sizeof(struct data_t));
	data->nval = INIT;
	data->max = INIT;
	data->data = NULL;

	i = setcitystatecountry(data, buf, in);
	print_normal(i, data, buf);
	kmlbegin(data, i);

	int j = 0;
	for(j = 0; j <= i; j++){

		free(data->data[j].city);
		free(data->data[j].state);
		free(data->data[j].country);
	}

	free(data->data);

	free(data);
	fclose(in);


	return 0;
}

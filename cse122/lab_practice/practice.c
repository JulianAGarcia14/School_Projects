#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 128

struct point_t {
	double x;
	double y;
};

struct data_t {
	int nval;
	/* current number of values in array */
	int max;
	/* allocated number of values */
	struct point_t *data;
	/* the data array */
};

enum {INIT = 1, GROW = 2};

void print_points(struct point_t *points, int num_points)
{
	int i;
	for (i = 0; i < num_points; i++)
	printf("(x = %lf, y = %lf)\n", points[i].x, points[i].y);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: points filename\n");
		return -1;
	}

	int num_points;
	char buf[LEN];
	int i = 0;
	FILE *in = fopen(argv[1], "r");
	char *s;
	struct data_t *data = malloc(sizeof(struct data_t));
	data->nval = INIT;
	data->max = INIT;
	data->data = NULL;

	while (fgets(buf, LEN, in)) {
		if (data->nval > data->max) {
			data->data = realloc(data->data, GROW * data->max *sizeof(struct point_t));
			data->max = GROW * data->max;
		} else if (data->data == NULL)
		data->data = malloc(INIT * sizeof(struct point_t));

		/* get the data from the file and place in the points array */
		/* this assumes points are space separated in the file */
		/* and no header information */
		/* 1.1 1.789
		* 2.07 3.6
		* etc
		*/
		s = strtok(buf, " ");
		/* get the x value */
		data->data[i].x = atof(s);
		s = strtok(NULL, " ");
		/* get y value */
		/* atof ignores the \n character */
		data->data[i].y = atof(s);
		i++;
		data->nval++;
	}

	print_points(data->data, i);
	/* this code leaks memory */
	/* point array is not freed -- you have to fix */
	fclose(in);
	free(data->data);
	free(data);
	return 0;
}

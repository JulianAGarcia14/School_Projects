/**
* @file life.c
*
* @author Julian Garcia
*
* @date 12/04/2018
*
* Assignment: Game of Life
*
* @brief functions for game of life program
*
* @details Contains functions which
*
* @bugs none
*
* @todo Finish flag functions, fix capturing user input.
*/

#include "life.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

/** Copys segmented strings t individual strings
 * @param s string to be parsed
 * @return string
 */
char *get_data(char *s)
{
	char *t = malloc((strlen(s) + 1) * sizeof(char));
	if (!t)
		end_prog(ENOMEM);
	return strncpy(t, s, strlen(s) + 1);
}

/** Handles errors in mem allocation
 * @return void
 */
void end_prog(int err)
{
	switch(err) {
		case ENOMEM:
		printf("malloc failed\n");
		/* errno.h has standard error codes */
		exit(ENOMEM);
	}
}


/** create a multi-dimensional array
 * @param rows rows based on height
 * @return string
 */
unsigned char **init_matrix(int rows, int cols)
{
	int i;
	int j;
	unsigned char **a;
	/* allocate rows */
	a = malloc(rows * sizeof(unsigned char *));
	if(!a){
		return NULL;
	}
	for(i = 0; i < rows; i++) {
	/* allocate cols for each row */
		a[i] = malloc(cols * sizeof(unsigned char));
		if (!a[i]) {
			for (j = 0; j < i; j++)

			free(a[j]);
			free(a);
			return NULL;

		}

	}
	return a;
}

/** Frees created matrix
 * @param a matrix to be removed
 * @param rows num of rows of matrix
 * @return void
 */
void free_matrix(unsigned char **a, int rows)
{
	int i = 0;
	for(i = 0; i < rows; i++){
		free(a[i]);
	}
	free(a);
}

/** Finds size of column/row
 * @param dimension size of height or width of screen
 * @param sprite size of sprite
 * @return size amount of columns/rows
 */
int find_size(int dimension, int sprite)
{
	int size;
	size = dimension/sprite;
	return size;
}

/**
* draw the game of life on the screen
* @param struct sdl_info_t sdl_info for SDL parameters
* @param unsigned char **life the grid of alive or dead cells
* @remarks The background is black. Make sure init_sdl_info()
* is called before using this function.

void sdl_render_life(struct sdl_info_t *sdl_info, unsigned char **life)
{


}
*/

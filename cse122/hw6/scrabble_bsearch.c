/**
 * @file scrabble_bsearch.c
 *
 * @author Julian Garcia
 *
 * @date 4/14/2019
 *
 * Assignment: Homework 6
 *
 * @brief Scrabble program which finds the best play for a set of letters, or if a word is in
 *	  the scrabble dictionary
 *
 * @details Uses realloc to place dictionary in structure array, uses allocated values to
 *          determine what is in the dictionary. Uses a C library bsearch rather than my own.
 *
 * @bugs only works up to a certain string length
 *
 * @todo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 128

struct data_t {
	int nval; 		/* current number of values in array */
	int max; 		/* allocated number of values */
	struct strings_t *data;		/* the data array */
};

struct strings_t {
	char *word;
};

enum {INIT = 1, GROW = 2};

int binary_search(struct data_t *data, char inword[LEN], int max);
void best_play(int max, char inword[LEN], struct data_t *data);
int ascending(void const *a, void const *b);
int points(char str[LEN]);
int comp(const void *s1, const void *s2);


int main(void)
{
	FILE *fp = fopen("scrabble.txt", "r");
	char buf[LEN];
	int i = 0;
	int input;
	int max_count;

	struct data_t *data = malloc(sizeof(struct data_t));
	data->nval = INIT;
	data->max = INIT;
	data->data = NULL;
	while (fgets(buf, LEN, fp)) {
		if (data->data == NULL)
			data->data = malloc(sizeof(struct strings_t));
		else if (data->nval > data->max) {
			data->data = realloc(data->data, GROW * data->max * sizeof(struct strings_t));
			data->max = GROW * data->max;
		}
		data->data[i].word = malloc(strlen(buf) * sizeof(char*));
		//data->data[i].word = buf;
		strncpy(data->data[i].word, buf, strlen(buf));
		i++;
                data->nval++;
	}
	max_count = i;
        /* overcounted */
        data->nval--;
	//use this to see if it is properly allocated
	//for(i = 0; i < data->nval; i++)
		//printf("data->data[%d] = %s\n", i, data->data[i].word);

	char inword[LEN];
	char s[LEN];
	char * answer;
	int z;
	char *key;
	char **key1;
	while(input != 3) {

		printf("Scrabble menu\n");
		printf("1. Find if a word is in the scrabble dictionary\n");
		printf("2. Determine best play from tiles\n");
		printf("3. quit\n");

		fgets(s, sizeof(s), stdin);
		sscanf(s ," %d", &input);
		switch(input) {
			case 1:
				printf("Enter word: ");
				fgets(inword, sizeof(inword), stdin);

				//answer = binary_search(data, inword, max_count);
				//NEW BINARY SEARCH
				key = inword;
				key1 = &key;
				answer = bsearch(key1, data->data, max_count, sizeof(data->data[0].word), comp);

				inword[strcspn(inword, "\n")] = 0;
				if (answer != NULL) {
					printf("%s is a valid scrabble word\n\n", inword);

				} else{
					printf("%s is not a valid scrabble word\n\n", inword);
				}
				break;
			case 2:
				printf("Enter tiles as a word: ");
				fgets(inword, sizeof(inword), stdin);
				best_play(max_count, inword, data);
				break;
			case 3:
			break;
		}
	}

	fclose(fp);
	for(i = 0; i < data->nval; i++){
		free(data->data[i].word);
	}
	free(data->data);
	free(data);

	return 0;
}


/** Compares two string values
 * @param s1, s2 values to be compared
 * @return A value given by strcmp representing whether the strings are equal
 */
int comp(const void *s1, const void *s2)
{
	return (strcmp(*(char **)s1, *(char **)s2));
}



/** Performs a binary search for given word
 * @param inword the given string
 * @param max the maximum index
 * @return true(1) or false(0)
 */
int binary_search(struct data_t *data, char inword[LEN], int max)
{
	int ret;
	int min = 0;
	int mid;
	while (min <= max) {
		mid = (min + max);
		mid = mid/2;
		ret = strcmp(inword, data->data[mid].word);

		if (ret < 0){
			max = mid - 1;

		}else if(ret > 0){
			min = mid + 1;
		} else{
			printf("%s", data->data[mid].word);
			return 1;
		}
	}
	return 0;


}

/** Parses input to find best play
 * @param inword the given string
 * @param max the maximum index
 * @return void
 */
void best_play(int max, char inword[LEN], struct data_t *data)
{
	char str[LEN];
	char str2[LEN];
	int ret;
	int i;
	int length;
	int point;
	int j;

	qsort(inword, strlen(inword), sizeof(char), ascending);
	length = strlen(inword);

	char ideal[LEN];
	int compare = 0;
	int k;
	for(j = 0; j <= strlen(inword); j++) {
		length = strlen(inword) - j;
		for(i = 0; i < max; i++){
			if (strlen(data->data[i].word) == length) {
				strncpy(str, data->data[i].word, length + 1);
				strncpy(str2, inword, strlen(inword));
				qsort(str, strlen(str), sizeof(char), ascending);
				for(k = 0; k <= strlen(str2); k++) {
					if(str[k] != str2[k]) {
						memmove(&str2[k], &str2[k + 1], strlen(str2) + 1);
					}
				}
				ret = strcmp(str, str2);
				if(ret == 0) {
					point = points(str);
					if(point > compare) {
						compare = point;
						strncpy(ideal, data->data[i].word, length + 1);
					}
				}
			}
		}
	}

	if(compare != 0) {
		printf("Best play for %d points is %s\n", compare, ideal);
		return;
	}


	printf("No play possible\n");
}

/** Compares two char values, used for qsort function
 * @param a, b values to be compared
 * @return difference between values
 */
int ascending(void const *a, void const *b)
{
	    return (*(char*)a - *(char*)b );
}

/** Determines the amount of points in a string
 * @param str the string to be evaluated
 * @return points
 */
int points(char str[LEN])
{
	int i;
	int points;
	int length;
	length = strlen(str) + 1;
	for(i = 0; i < length; i++){
		switch (str[i]) {
			case 'a':
				points = points + 1;
				break;
			case 'b':
				points = points + 3;
				break;
			case 'c':
				points = points + 3;
				break;
			case 'd':
				points = points + 2;
				break;
			case 'e':
				points = points + 1;
				break;
			case 'f':
				points = points + 4;
				break;
			case 'g':
				points = points + 2;
				break;
			case 'h':
				points = points + 4;
				break;
			case 'i':
				points = points + 1;
				break;
			case 'j':
				points = points + 8;
				break;
			case 'k':
				points = points + 5;
				break;
			case 'l':
				points = points + 1;
				break;
			case 'm':
				points = points + 3;
				break;
			case 'n':
				points = points + 1;
				break;
			case 'o':
				points = points + 1;
				break;
			case 'p':
				points = points + 3;
				break;
			case 'q':
				points = points + 10;
				break;
			case 'r':
				points = points + 1;
				break;
			case 's':
				points = points + 1;
				break;
			case 't':
				points = points + 1;
				break;
			case 'u':
				points = points + 1;
				break;
			case 'v':
				points = points + 4;
				break;
			case 'w':
				points = points + 4;
				break;
			case 'x':
				points = points + 8;
				break;
			case 'y':
				points = points + 4;
				break;
			case 'z':
				points = points + 10;
				break;


		}
	}
	return points;
}

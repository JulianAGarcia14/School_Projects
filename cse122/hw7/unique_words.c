/**
 * @file unique_words.c
 *
 * @author Julian Garcia
 *
 * @date 5/01/2019
 *
 * Assignment: Homework 7 REDO
 *
 * @brief Program which parses unique words from text file
 *
 * @details Uses 1000 most common words to isolate unique words. Both a list of 1000
 *	    common words and of the text file are stored in hash tables. I believe I hashed
 *	    and stored the values correctly, just haven't figured out how to sort properly.
 *
 * @bugs Valgrind doesn't like it, values of repeated words is definitely wrong
 *
 *
 *
 * @todo Fix so that it prints the correct number of repetitions.
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lex_word.h"
#include <string.h>
#include <ctype.h>

#define LEN 4096
enum {INIT = 1, GROW = 2};

struct node_t
{
	char key[LEN];
	int value;
	struct node_t *next;
};

struct arrayitem_t
{
	struct node_t *head;
	struct node_t *tail;
};


void init_array(struct arrayitem_t *array, int max);
void insert(char *key, int value, struct arrayitem_t *array, int max, int *size, int mmax);
int find(struct node_t *list, char *key);
//struct node_t *
void get_element(struct node_t *list, int find_index, int i);
void deleteList(struct node_t **head_ref);
unsigned long hash(char *str);

//demo program of lexer for words
/*  convert string to lowercase */
void tolowercase(char *s)
{
        while (*s) {
                *s = tolower(*s);
                s++;
        }
}

/** Compares two string values
 * @param a, b values to be compared
 * @return A value given by strcmp representing whether the strings are equal
 *
 */
int comp(const void *a, const void * b){
	const char *pa = (const char*)a;
	const char *pb = (const char*)b;
	return strcmp(pa, pb);
}

/** Compares two string values
 * @param a, b values to be compared
 * @return A value given by strcmp representing whether the strings are equal
 */
int qcomp(const void *a, const void * b){
	const char *pa = *(const char**)a;
	const char *pb = *(const char**)b;
	return strcmp(pa, pb);
}

/** Tokenizes, sorts, hashes, and prints given text.
 * @return void
 */
void word_dump(char *infile, struct arrayitem_t *array, int max, int check, struct arrayitem_t *array2)
{

	int value = 1;
	int size = 0;


        FILE *in = fopen(infile, "r");
        assert(in);
        char word[LEN];
        int token;
	int index = -1;
	int i = 0;
	float n;

        while (1) {
                switch (token = get_tok(in, word, sizeof(word))) {
                case TOK_WORD:
                        if (strcmp(word, "")) {
                                tolowercase(word);
                                //printf("%s\n", word);
				if(check == 0) {
					//printf("%s\n", word);
					while(index == -1 && i < 250){
						if(array[i].head != NULL){
							index = find(array[i].head, word);
						}
						i++;
					}
					if(index == -1) {
						insert(word, value, array, max, &size, max);
					}

				} else if(check == 1) {

					while(index == -1 && i < 250) {
						if(array2[i].head != NULL){
							index = find(array2[i].head, word);
						}
						i++;
					}
					if(index == -1) {
						insert(word, value, array, max, &size, max);
					}
				}
                        }
                        break;
                case TOK_ERR:
                        //printf("err: %s\n", word);
                        break;
                case TOK_EOF:
			fclose(in);
			//Calculating Load factor
			n = ((float) size) / ((float) max);
			//printf("Load Factor is %f\n", n);

			return;
                }
        }
	fclose(in);
}

/** Hashes char string using Bernstein's algorithm
 * @return void
 */
unsigned long hash(char *str)
{
	int hash = 5381; //5381
	int c;
	while (c = *str++) {
		//hash = ((hash << 5) + hash) + c;
		hash = hash * 33 + c;
	}
	return hash;
}


int main(int argc, char **argv)
{
	//Used Table Size: 5000 for meta, 12000 for gadsby
        if (argc != 3) {
                printf("usage: words filename, hash table size\n");
                exit(EXIT_FAILURE);
        }

	//printf("Hash table size = %d\n", atoi(argv[2]));
	char *thousand = "1000_words.txt";
	int max1000 = 250;/* Determines the maximum capacity of Hash Table array */
	int maxbooks = atoi(argv[2]);/* Determines the maximum capacity of Hash Table array */

	int check = 0;
	int i;
	struct node_t *temp;


	struct arrayitem_t *array1;
	array1 = malloc(max1000 * sizeof(struct arrayitem_t));
	init_array(array1, max1000);
	word_dump(thousand, array1, max1000, check, array1);

	/* for(i = 0; i < max1000; i++){
		if (array1[i].head != NULL){
			temp = array1[i].head;
			while(temp!=NULL){
				printf("%s, %d\n",temp->key, temp->value);
				temp = temp->next;
			}
		}
	} */

	check = 1;
	struct arrayitem_t *array2;
	array2 = malloc(maxbooks * sizeof(struct arrayitem_t));
	init_array(array2, maxbooks);
	word_dump(argv[1], array2, maxbooks, check, array1);

	/*
	for(i = 0; i < maxbooks; i++){
		if (array2[i].head != NULL){
			temp = array2[i].head;
			while(temp!=NULL){
				printf("%s, %d\n",temp->key, temp->value);
				temp = temp->next;
			}
		}
	}
	*/

	int num = INIT;
	int mmax = INIT;
	char **list = NULL;
	char str[] = "	";
	char str2[2];
	char *t = NULL; //= malloc(sizeof(char*));

	//t = malloc(sizeof(char*) * LEN);
	for(i = 0; i < maxbooks; i++){
		if (array2[i].head != NULL){
			temp = array2[i].head;
			while(temp!=NULL){
				if(list == NULL) {
					list = malloc(sizeof(char *));
				} else if (num > mmax) {
					list = realloc(list, GROW * mmax * sizeof(char *));
					mmax = GROW * mmax;
				}

				//t = (char *) calloc(strlen(t), sizeof(char*));
				t = (char *) realloc(t, sizeof(char*) * strlen(temp->key));
				//strncpy(t, temp->key, strlen(temp->key));
				t = temp->key;

				//strncpy(t, temp->key, strlen(temp->key));
				sprintf(str2, "%d", temp->value);
				strncat(t, str, strlen(t) + strlen(str));
				strncat(t, str2, strlen(t) + strlen(str2));

				list[num - 1] = t;
				//t = (char *) realloc(t, sizeof(char*) * strlen(temp->value));
				//strcat(list[num - 1], str);
				//strcat(list[num - 1], str2);


				num++;
				temp = temp->next;
				//free(t);
				//t = '\0';
				//free(t);
			}
		}
	}


	num--;
	qsort(list, num, sizeof(list[0]), qcomp);
	/* print sorted list */
	for(i = 0; i < num; i++){
		printf("%s\n", list[i]);
	}


	//free(t);


	for(i = 0; i < max1000; i++)
	{
		deleteList(&array1[i].head);
	}
	for(i = 0; i < maxbooks; i++)
	{
		deleteList(&array2[i].head);

	}

	free(array1);
	free(array2);

        return 0;
}

/** For initializing the Hash Table
 * @return void
 */
void init_array(struct arrayitem_t *array, int max)
{
	int i = 0;
	for (i = 0; i < max; i++)
        {
		array[i].head = NULL;
		array[i].tail = NULL;
	}
}

/** Inserts node into hash index
 * @return void
 */
void insert(char *key, int value, struct arrayitem_t *array, int max, int *size, int mmax)
{

	unsigned long index = hash(key);

	while(index > mmax){
		index = index % max;
	}

	struct node_t *list = malloc(sizeof(struct node_t));

	list = array[index].head;

	struct node_t *item = malloc(sizeof(struct node_t));
	//item->key = key;
	strncpy(item->key, key, strlen(key) + 1);
	item->value = value;
	item->next = NULL;

	if (list == NULL)
        {
		array[index].head = item;
		array[index].tail = item;
		(*size)++;
	}
        else
        {
		int find_index = find(list, key);
		if (find_index == -1)
                {
			array[index].tail->next = item;
			array[index].tail = item;
			(*size)++;

		}else
                {
			//struct node_t *element = get_element(list, find_index);
			get_element(array[index].head, find_index, 0);
			//element->value = value + 1;
			(*size)++;

		}
	}

	free(item);
}

/** Finds the key of a linked list
 * @return index or -1 if not found
 */
int find(struct node_t *list, char *key)
{
	int retval = 0;
	struct node_t *temp = list;
	while (temp != NULL)
        {
		//if (temp->key == key)
		if (comp(temp->key, key) == 0)
                {
			return retval;
		}
  		temp = temp->next;
		retval++;
	}
	return -1;
}

/** Finds the node (Linked List item) located at given find_index and increments value
 * @return void
 */
void get_element(struct node_t *list, int find_index, int i)
{
	//int i = 0;
	//struct node_t *temp = list;
	if (i != find_index)
        {
		i++;
		get_element(list->next, find_index, i);
		//temp = temp->next;
		if(i == find_index){
			list->value++;
		}

	}
	//return temp;
}

/** Function to delete the entire linked list
 * @return void
 */
void deleteList(struct node_t **head_ref)
{
	struct node_t *current;
   	current = *head_ref;
   	struct node_t *next;

   	while (current != NULL)
   	{
       		next = current->next;
       		free(current);
       		current = next;
   	}

   	*head_ref = NULL;
}

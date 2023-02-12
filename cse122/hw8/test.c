/**
 * @file test.c
 *
 * @author Julian Garcia
 *
 * @date 4/29/2019
 *
 * Assignment: Homework 8
 *
 * @brief  Contains main function and user functions for avl.c
 *
 * @details Parses input text to avl tree and does multiple operations
 *	    on the list
 *
 * @bugs
 *
 * @todo
 */


#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define LEN 1024

/** Prints out search success or failure
 * @param dio, key to find
 * @return void
 */
void lookup(struct avl_node_t *find, char *dio){
	if(find == NULL){
		printf("Cannot find %s\n\n", dio);
	} else {
		printf("Found key %s\n", (char *)find->key);
		printf("Value Is:\n %s\n\n", (char *)find->value);
	}

}

/** Prints complete node
 * @return void
 */
void print_node(struct avl_node_t *node)
{
	printf("%s%s\n\n", (char *)node->key, (char *)node->value);
}

/** Prints key of node
 * @return void
 */
void print_key(struct avl_node_t *node)
{
	printf("%s", (char *)node->key);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: filename\n");
		exit(EXIT_FAILURE);
	}
	int i = 1;
	int j = 0;
	//char *a;
	char buf[LEN];
	char a[40][LEN];
	char b[40][LEN];
	struct avl_node_t *root = NULL;

	FILE *fp = fopen(argv[1], "r");
	assert(fp);

	while (fgets(buf, LEN, fp)) {
		if(i%2 == 0){
			strtok(buf, "\n");
			strcpy(b[j], buf);
			root = insert(root, &a[j - 1], &b[j]);
			j++;
			//free(a);
			//a = NULL;
		}else {
			strcpy(a[j], buf);
			j++;
			//a = buf; //(char*)malloc(strlen(buf) + 1);
		}
		i++;
	}

	printf("Inorder\n");
	inorder(root, print_node);
	printf("\n\n");
	printf("Preorder\n");
	preorder(root, print_key);
	printf("\n\n");
	printf("Postorder\n");
	postorder(root, print_key);
	printf("\n\n");

	char dio[] = "Dionysus\n";
	char jup[] = "Jupiter\n";
	struct avl_node_t *find = avl_find(root, &dio);
	lookup(find, dio);
	find = avl_find(root, &jup);
	lookup(find, jup);


	char hestia[] = "Hestia\n";
	char artemis[] = "Artemis\n";
	char hades[] = "Hades\n";
	char pandora[] = "Pandora\n";
	char hephaestus[] = "Hephaestus\n";
	char zeus[] = "Zeus\n";

	printf("Deleting Hestia\n");
	root = delete_node(root, &hestia);
	printf("Deleting Artemis\n");
	root = delete_node(root, &artemis);
	printf("Deleting Hades\n");
	root = delete_node(root, &hades);
	printf("Deleting Pandora\n");
	root = delete_node(root, &pandora);
	printf("Deleting Hephaestus\n");
	root = delete_node(root, &hephaestus);
	printf("Deleting Zeus\n\n");
	root = delete_node(root, &zeus);
	printf("Inorder List:\n");
	inorder(root, print_key);
	delete_all(root);
	fclose(fp);
	return 0;
}

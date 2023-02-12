#include "avl.h"
#include <stdlib.h>
#include <stdio.h>


void print_node(struct avl_node_t *node)
{
	printf("%s%s\n", (char *)node->key, (char *)node->value);
}

void print_key(struct avl_node_t *node)
{
	printf("%s%s\n", (char *)node->key);
}

int main(void)
{
	struct avl_node_t *root = NULL;
	int a[] = {10, 20, 30, 5, 3, 8, 25, 40};
	root = insert(root, &a[0], &a[1]);
	root = insert(root, &a[1], &a[2]);
	root = insert(root, &a[2], &a[3]);
	root = insert(root, &a[3], &a[4]);
	root = insert(root, &a[4], &a[5]);
	root = insert(root, &a[5], &a[6]);
	root = insert(root, &a[6], &a[7]);
	root = insert(root, &a[7], &a[0]);
	printf("Inorder\n");
	inorder(root, print_node);
	printf("\n\n");
	printf("Preorder\n");
	preorder(root);
	printf("\n\n");
	printf("Postorder\n");
	postorder(root);
	printf("\n\n");

	struct avl_node_t *find = avl_find(root, &a[2]);
	if(find == NULL){
		printf("Not found\n\n");
	} else {
		printf("Key %d found\n\n", *(int *)find->key);
	}

	root = delete_node(root, &a[0]);
	inorder(root, print_key);
	delete_all(root);
	return 0;
}

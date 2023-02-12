/**
 * @file avl.c
 *
 * @author Julian Garcia
 *
 * @date 4/29/2019
 *
 * Assignment: Homework 8
 *
 * @brief  Contains functions for test.c
 *
 * @details Contains functions for inserting and sorting nodes
 *	    into an avl tree
 *
 * @bugs
 *
 * @todo
 */


#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Compares two string values
 * @param a, b values to be compared
 * @return A value given by strcmp representing whether the strings are equal
 */
int comparator(const void *a, const void * b){
	const char *pa = (const char*)a;
	const char *pb = (const char*)b;
	return strcmp(pa, pb);
}

/** Finds height of node
 * @return Height of node
 */
int height(struct avl_node_t *root)
{
	if (!root)
		return -1;

	else
		return root->height;
}

/** Compares two values to find which is greater
 * @param a, b values to be compared
 * @return greater value
 */
int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}


/* LL new node inserted into the left subtree of the left subtree of the critical node */
struct avl_node_t *single_rotate_left(struct avl_node_t *x)
{
	struct avl_node_t *w = x->left;
	x->left = w->right;
	w->right = x;

	x->height = max(height(x->left), height(x->right)) + 1;
	w->height = max(height(w->left), x->height) + 1;
	return w; 		/* new root */

}


/* RR new node inserted into the right subtree of the right subtree of the critical node */
struct avl_node_t *single_rotate_right(struct avl_node_t *w)
{
	struct avl_node_t *x = w->right;
	w->right = x->left;
	x->left = w;

	w->height = max(height(w->left), height(w->right)) + 1;
	x->height = max(height(x->right), w->height) + 1;
	return x; 		/* new root */

}

/* LR rotation new node inserted into the right subtree of the left subtree of the critical node  */
struct avl_node_t *double_rotate_left(struct avl_node_t *z)
{
	z->left = single_rotate_right(z->left);
	return single_rotate_left(z);
}

/* RL rotation new node inserted into the left subtree of the right subtree of the critical node  */
struct avl_node_t *double_rotate_right(struct avl_node_t *z)
{
	z->right = single_rotate_left(z->right);
	return single_rotate_right(z);
}


/** Inserts nodes into avl tree
 * @param key, key of node to be inserted
 * @param value, value of key to be inserted
 * @return avl tree
 */
struct avl_node_t *insert(struct avl_node_t *root, void *key, void *value)
{
	if (!root) {
		root = malloc(sizeof(struct avl_node_t));
		if (!root) {
			printf("insert: malloc error\n");
			return NULL;
		}
		else {
			root->key = key;
			root->value = value;
			root->height = 0;
			root->left = NULL;
			root->right = NULL;
		}

	}
	//else if(key < root->key) { /* left subtree */
	else if(comparator(key, root->key) < 0) { /* left subtree */
		root->left = insert(root->left, key, value);
		if ((height(root->left) - height(root->right)) == 2) {
			//if (key < root->left->key) /* left subtree */
			if (comparator(key, root->left->key) < 0) /* left subtree */
				root = single_rotate_left(root); /* LL */
			else 	/* LR */
				root = double_rotate_left(root);

		}
	}
	//else if (key > root->key) { /* right subtree */
	else if(comparator(key, root->key) > 0) { /* left subtree */
		root->right = insert(root->right, key, value);
		if ((height(root->right) - height(root->left)) == 2) {
			//if (key < root->right->key) /* left subtree */
			if (comparator(key, root->right->key) < 0) /* left subtree */
				root = double_rotate_right(root); /* RL */
			else 	/* RR */
				root = single_rotate_right(root);
		}
	}

	root->height = max(height(root->left), height(root->right)) + 1;

	return root;
}

/** Rebalances avl tree on deletion
 * @param root, tree to be balanced
 * @return balanced tree
 */
struct avl_node_t *balance(struct avl_node_t *root)
{
	if(!root){
		return NULL;
	}
	if ((height(root->left) - height(root->right)) == 2) {
		if(height(root->left->left) > height(root->left->right)){
			root = single_rotate_left(root);
		} else {
			root = double_rotate_left(root);
		}
	} else if((height(root->right) - height(root->left)) == 2){
		if(height(root->right->right) > height(root->right->left)){
			root = single_rotate_right(root);
		} else {
			root = double_rotate_right(root);
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

/** Finds largest of left subtree
 * @return largest of left subtree
 */
struct avl_node_t *find_max(struct avl_node_t *root){
	while(root && root->left) {
		root = root->left;
	}
	return root;
}


/* this is a delete for a bst not an avl tree */
/* make it an avl deletion by accounting for rotations after you delete a node */
struct avl_node_t *delete_node(struct avl_node_t *root, void *key)
{
	struct avl_node_t *tmp;

	/* find node */
	if (root == NULL)
		printf("element not found\n");
	//else if(key < root->key) { /* left subtree */
	else if(comparator(key, root->key) < 0) { /* left subtree */
		root->left = delete_node(root->left, key);
		return balance(root);
	}
	//else if (key > root->key) { /* right subtree */
	else if (comparator(key, root->key) > 0) { /* right subtree */
		root->right = delete_node(root->right, key);
		return balance(root);
	}
	else { 			/* found element */
		if (root->left && root->right) {
			/* two children */
			/* replace with largest in left subtree */
			/* you need to implement the find_max function */
			/* uncomment the next two lines once find_max is implemented */
			tmp = find_max(root->left);
			root->key = tmp->key;
			root->left = delete_node(root->left, root->key);
		}
		else {

			tmp = root;
			/* no children */
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left != NULL) 			/* one child */
				root = root->left;
			else
				root = root->right;

			free(tmp);
		}
	}

	return root;
}

/** Deletes all nodes in avl tree
 * @return void
 */
void delete_all(struct avl_node_t *root)
{
	if(!root){
		return;
	}
	delete_all(root->left);
	delete_all(root->right);
	free(root);
}

/** Prints avl tree inorder
 * @param uprint, user defined print function
 * @return vid
 */
void inorder(struct avl_node_t *node, void (*uprint)(struct avl_node_t *node))
{
	if (node != NULL) {
		inorder(node->left, uprint);
		//printf("%s%s\n", (char *)node->key, (char *)node->value);
		uprint(node);
		inorder(node->right, uprint);
	}
}

/** Prints avl tree preorder
 * @param uprint, user defined print function
 * @return vid
 */
void preorder(struct avl_node_t *node, void (*uprint)(struct avl_node_t *node))
{
	if (node != NULL) {
		//printf("%s", (char *)node->key);
		uprint(node);
		preorder(node->left, uprint);
		preorder(node->right, uprint);
	}
}

/** Prints avl tree postorder
 * @param uprint, user defined print function
 * @return vid
 */
void postorder(struct avl_node_t *node, void (*uprint)(struct avl_node_t *node))
{
	if (node != NULL) {
		postorder(node->left, uprint);
		postorder(node->right, uprint);
		uprint(node);
		//printf("%s", (char *)node->key);
	}
}

/** Searches for node of given key
 * @param key, key to be found
 * @return node of key, or NULL if not found
 */
struct avl_node_t *avl_find(struct avl_node_t *root, void *key)
{
	struct avl_node_t *current = root;

	while(current && comparator(current->key, key) != 0){
		if(comparator(current->key, key) < 0){
			current = current->right;
		}else {
			current = current->left;
		}
	}
	return current;
}

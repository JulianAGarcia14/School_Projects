#ifndef AVL_H_
#define AVL_H_

struct avl_node_t {
	void *key;
	int height; 		/* balance factor */
	void *value;

	struct avl_node_t *left;
	struct avl_node_t *right;
};

int height(struct avl_node_t *root);
struct avl_node_t *single_rotate_left(struct avl_node_t *x);
struct avl_node_t *single_rotate_right(struct avl_node_t *w);
struct avl_node_t *double_rotate_right(struct avl_node_t *z);
struct avl_node_t *double_rotate_left(struct avl_node_t *z);
struct avl_node_t *insert(struct avl_node_t *root, void *key, void *value);
/* this performs a bst deletion only */
struct avl_node_t *delete_node(struct avl_node_t *root, void *key);
void inorder(struct avl_node_t *node, void (*uprint)(struct avl_node_t *node));

//Write docs
struct avl_node_t *avl_find(struct avl_node_t *root, void *key);
void postorder(struct avl_node_t *node, void (*uprint)(struct avl_node_t *node));
void preorder(struct avl_node_t *node, void (*uprint)(struct avl_node_t *node));
void delete_all(struct avl_node_t *root);
struct avl_node_t *find_max(struct avl_node_t *root);
struct avl_node_t *balance(struct avl_node_t *root);

#endif

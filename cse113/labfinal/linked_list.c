#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node_t {
	struct node_t * next;
	int data;
};

struct node_t * create_node (int data) {
	//corrected Julian Garcia 12/05/18
	struct node_t * node = malloc(sizeof(struct node_t));
	node -> next = NULL;
	node -> data = data;
	return node;
}

struct node_t * add_head (struct node_t * head, struct node_t * node) {
	//corrected Julian Garcia 12/05/18
	node -> next = head;
	head = node;
	return head;
}

void delete_list(struct node_t * head) {
	//corrected Julian Garcia 12/05/18
	struct node_t *tmp = head;
	while (head) {
		head = head -> next;
	//	free(tmp -> data);
		free(tmp);
		tmp = head;
	}
	(head = NULL);
}

void print_list(struct node_t * head) {
	//corrected Julian Garcia 03/24/18
	while (head != NULL) {
	//for ( ; head != NULL; head = head->next) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}



/////////////////////////////////////////////////////////////////////



int list_length(struct node_t * head) {
	//your code goes here
	int count = 0;

	for( ; head != NULL; head = head->next)
		count++;

	return count;
}

void delete_duplicates(struct node_t * head) {
	//your code goes here
	struct node_t *tmp = head;
	while (head) {
		head = head->next;
		if(tmp->data == head->data) {
			//free(tmp->data);
			free(tmp);
			tmp = head;
		} else{
			tmp = head;
		}
	}
}


int main() {
	int arr1[] = {1, 2, 3, 124, 5, 4, 3, 2, 1};
	int arr2[] = {1, 72, 1, 2, 5, 117, 2, 5, 8, 6, 4, 2, 8};
	struct node_t * head1, * head2;
	int i;

	head1 = head2 = NULL;

	for (i = 0; i < sizeof(arr1)/sizeof(int); i++)
		head1 = add_head(head1, create_node(arr1[i]));

	for (i = 0; i < sizeof(arr2)/sizeof(int); i++)
		head2 = add_head(head2, create_node(arr2[i]));

	printf("List 1:\n");
	print_list(head1);
	printf("List 2:\n");
	print_list(head2);

	printf("\nThe length of list one is %d.\n", list_length(head1));
	printf("\nThe length of list two is %d.\n", list_length(head2));


	delete_duplicates(head1);
	delete_duplicates(head2);

	printf("After duplicates have been deleted:\n");
	printf("List 1:\n");
	print_list(head1);
	printf("List 2:\n");
	print_list(head2);



	delete_list(head1);
	delete_list(head2);
	return 0;
}

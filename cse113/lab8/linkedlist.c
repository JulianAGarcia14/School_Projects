/**
* @file linkedlist.c
*
* @author Julian Garcia
*
* @date 11/21/2018
*
* Assignment: Lab 8
*
* @brief Contains functions for a linked list
*
* @details Allows for manipulation of linked list
*
* @bugs Just doesnt work
*
* @todo Fix it
*/


/* function declarations needed for the linked list */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node_t {

	double x;
	struct node_t *next;
};

struct node_t *create_node(double n);
void print_node(struct node_t *node, int i);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t *insert_tail(struct node_t *head, struct node_t *node, int a);
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos, int a);
int count_nodes(struct node_t *head);
struct node_t *find_node(struct node_t *head, int n);
struct node_t *delete_node(struct node_t *head, int n);
void delete_list(struct node_t *head);


/** Takes user input as an int
 * @return user input
 */
int get_info()
{
	int info;
	scanf("%d", &info);
	return info;
}

int main() {
	/*add code here
	work on design/pseudo-code
	before you start coding!
	Drawing pictures really does help!
	*/
	int info;
	int input;
	int input2;
	int input3;
	int input4;
	/* Start with the empty list */
	struct node_t* head = NULL;

	while (info != 10) {
		printf("What funtion do you want to use?\n");
		printf("Press 1 to print a node\n");
		printf("Press 2 to  print the list of nodes\n");
		printf("Press 3 to insert to head of list\n");
		printf("Press 4 to insert to end of list\n");
		printf("Press 5 to insert anywhere in list\n");
		printf("Press 6 to count numbers in list\n");
		printf("Press 7 to find a node\n");
		printf("Press 8 to delete a node\n");
		printf("Press 9 to delete list\n");
		printf("Press 10 when you're done\n");
		scanf("%d", &info);

		if (info > 10 || info < 1) {
			printf("That is not an option!\n");
			return 2;
		}

		switch(info) {
			case 1:
				printf("Which node would you like to print?\n");
				printf("There are currently %d nodes in the list.\n", count_nodes(head));
				int input5 = get_info();
				if(input5 > count_nodes(head)) {
					printf("That is not an option!\n");
					break;
				}
				print_node(head, input5);

			break;

			case 2:
				printf("\n Created Linked list is: ");
				print_list(head);

			break;

			case 3:
				printf("What value would you like to assign to the head of the list?\n");
				int input6 = get_info();
				create_node(input6);
				insert_head(head, new_node);

			break;

			case 4:

				printf("What value would you like to assign to the end of the list?\n");
				int input7 = get_info();
				create_node(input7);
				insert_tail(head, new_node)

			break;

			case 5:

				printf("There are currently %d nodes in the list.\n", count_nodes(head));
				printf("Where would you like to print the node?\n");
				printf("Enter the number of where you'd like this node to be placed\n");
				input = get_info();
				if(input5 > count_nodes(head)) {
					printf("That is not an option!\n");
					break;
				}

				printf("Enter the value you'd like to assign to the list\n");
				input2 = get_info();

			break;

			case 6:
				printf("There are currently %d nodes in the list.\n", count_nodes(head));
			break;

			case 7:
				printf("There are currently %d nodes in the list.\n", count_nodes(head));
				printf("Which value would you like to find?\n");
				printf("Enter the number of the value you want to find.\n");
				input3 = get_info();

				int answer = find_node(head, input3);
				if(answer != false){
				printf("This was found at node %d\n", answer);
		         	}
			break;

			case 8:
				printf("There are currently %d nodes in the list.\n", count_nodes(head));
				printf("Which node would you like to delete?\n");
				input4 = get_info();
				if(input4 > count_nodes(head)) {
					printf("That is not an option!\n");
					break;
				}

				delete_node(head, input4);


			break;

			case 9:

				delete_list(head);
				printf("There are currently %d nodes in the list.\n", count_nodes(head));

			break;

			case 10:
				return 2;
			break;
		}
	}
	delete_list(head)
	return 0;
}


/** Creates a node
 * @param n the value to be inserted in the node
 */
struct node_t *create_node(double n)
{
	/* 1. allocate node */
	node_t * new_node; //= (struct Node*) malloc(sizeof(struct node_t));
	new_node = malloc(sizeof(node_t));

	/* 2. put in the data */
	new_node->x = n;

}

/** Prints a certain node
 * @param i node user wants to print
 * @return void
 */
void print_node(struct node_t *node, int i)
{

	struct node_t* current = node;


	    int count = 0;
	    while (current != NULL)
	    {
	        if (count == i)
			printf(" %d ", node->x);
			printf(" %d ", node->next);
			return(current->x);
	        count++;
	        current = current->next;
	    }

}
/** Prints overall node list.
 * @return void
 */
void print_list(struct node_t *head)
{
	int i = 0;
	while (node != NULL)
	{
		print_node(head, i);
		i++;
	}

}
/** Inserts head node
 * @param n number to be put in head node
 */
struct node_t *insert_head(struct node_t *head, double n)
{

	/* 1. allocate node */
	node_t * new_node; //= (struct Node*) malloc(sizeof(struct node_t));
	new_node = malloc(sizeof(node_t));

	/* 2. put in the data */
	new_node->x = n;
	/* 3. Make next of new node as head */
	new_node->next = (*head);

	/* 4. move the head to point to the new node */
	(*head) = new_node;

}
/** Inserts tail node
 * @param n number user wants to put in tail node
 */
struct node_t *insert_tail(struct node_t *head, double n)
{


	struct node_t *last = *head;

	node_t * new_node;
	new_node = malloc(sizeof(node_t));


	new_node->x = n;
	new_node->next = NULL;


	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}


	while (last->next != NULL)
		last = last->next;


	last->next = new_node;
	return;

}
/** Inserts node to middle of list
 * @param pos position of node
 * @param n number to be put in node
 * @return void
 */
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos, double n)
{

	if (node == NULL)
	{
	printf("the given previous node cannot be NULL");
	return;
	}


	node_t * new_node;
	new_node = malloc(sizeof(node_t));


	new_node->x = n;

	node->next = prev_node->next;


	prev_node->next = new_node;

}
/** Counts total nodes in list
 */
int count_nodes(struct node_t *head)
{
	int count = 0;
	struct node_t* current = head;
	while (current != NULL)
	{
    		count++;
    		current = current->next;
	}
	return count;

}
/** Finds node with certain value in it
 * @param n number to be found
 */
struct node_t *find_node(struct node_t *head, int n)
{
	int i = 0;
	struct node_t* current = head;
        while (current != NULL)
        {
            if (current->x == n)
                return i;
            current = current->next;
	    i++;
        }
	printf("This value was not found\n");
        return false;

}
/** Deletes certain node
 * @param n index of node
 */
struct node_t *delete_node(struct node_t *head, int n)
{

	   if (*head == NULL)
	      return;


	   struct node_t* temp = *head_ref;


	    if (position == 0)
	    {
	        *head_ref = temp->next;
	        free(temp);
	        return;
	    }


	    for (int i=0; temp!=NULL && i<n-1; i++)
	         temp = temp->next;


	    if (temp == NULL || temp->next == NULL) {
	         return;
	 }

	    struct node_t *next = temp->next->next;


	    free(temp->next);

	    temp->next = next;

}
/** Deletes entire list
 * @return void
 */
void delete_list(struct node_t *head)
{

 	struct node_t* current = *head;
 	struct node_t* next;

 	while (current != NULL)
 	{
     		next = current->next;
     		free(current);
     		current = next;
 	}


 	*head = NULL;

}

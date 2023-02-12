/**
* @file lab9.c
*
* @author Julian Garcia
*
* @date 10/27/2018
*
* Assignment: Lab 9
*
* @brief a program that permorms binary calculations
*
* @details Uses doubly linked lists to store given values by user and the value found through calculation
*
* @bugs none
*
* @todo Finish flag functions, fix capturing user input.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

struct bit_t {
	char *n;
	/* store either 0 or 1 not ’0’ or ’1’ */
	struct bit_t *prev;
	struct bit_t *next;
};

struct cpu_t {
	int word_size;
	int unsign;
	//0 -- signed, 1 for unsigned
	//flags
	int overflow;
	int carry;
	int sign;
	int parity;
	int zero;

	//head is msb
	struct bit_t *r1_head;
	struct bit_t *r1_tail;
	struct bit_t *r2_head;
	struct bit_t *r2_tail;
	struct bit_t *r3_head;
	struct bit_t *r3_tail;
};

int overflow();
int carry_out();
int signflag();
int parity();
int zeroflag();
char *addBinary(char *a, char *b, int len);
char *subBinary(char *a, char *b, int len);

char *get_data(char *s);
struct bit_t *create_node(void);
struct bit_t *new_node(char *n);
void end_prog(int err);
void print_list(struct bit_t *head);
struct bit_t *add_front(struct bit_t *head, struct bit_t *node, struct bit_t *tail);
struct bit_t *free_list(struct bit_t *head);
int count_nodes(struct bit_t *head);
char *get_data(char *s);
void rstrip(char *s);
void print_node(struct bit_t *node);

int main(void)
{

	char *s, *n1, *n2, *n3;
	struct cpu_t cpu;
	int len;
	char str[2];
	char str2[2];


	printf("enter word size:\n");
	//scanf("%d", &cpu.word_size);
	fgets(str, sizeof(str), stdin);
	sscanf(str ,"%d", &cpu.word_size);
	getchar();
	printf("unsigned values [0 for no, 1 for yes]:\n");
	//scanf("%d", &cpu.unsign);
	fgets(str2, sizeof(str2), stdin);
	sscanf(str2 ,"%d", &cpu.unsign);
	getchar();

	len = cpu.word_size + 1;
	len = 2*len;
	char buf[len];

	printf("enter binary expression, use space to seperate two terms:\n");
	/* grab data from user */
	while(fgets(buf, len, stdin)) {
		/* remove new line in buf */
		rstrip(buf);

		/* account for 0 */
		s = strtok(buf, " ");
		n1 = get_data(s);


		s = strtok(NULL, "\n");
		n2 = get_data(s);

		/* what type of list is this? */
		char n_n1[1];
		char n_n2[1];
		int i = 0;
		while(i < len) {

			n_n1[0] = n1[i];
			while(n_n1[0] != '\0') {
				cpu.r1_head = add_front(cpu.r1_head, new_node(n_n1), cpu.r1_tail);
			}
			n_n2[0] = n2[i];
			while(n_n2[0] != '\0') {
				cpu.r2_head = add_front(cpu.r2_head, new_node(n_n2), cpu.r1_tail);
			}
			i++;
		}

		int op;
		char *n_n3 = NULL;
		int j = 0;
		printf("Would you like to add or subtract the two terms?\n");
		printf("1 for addition\n2 for subtraction\n");
		scanf("%d", &op);

		if(op == 1) {
			char *n3 = addBinary(n1, n2, len);
			while(i < len) {

				*n_n3 = n3[j];
				while(*n_n3 != '\0') {
					cpu.r3_head = add_front(cpu.r3_head, new_node(n_n3), cpu.r3_tail);
				}
				j++;
			}
		} else if (op == 2) {
			char *n3 = subBinary(n1, n2, len);
			while(i < len) {

				*n_n3 = n3[j];
				while(*n_n1 != '\0') {
					cpu.r3_head = add_front(cpu.r3_head, new_node(n_n3), cpu.r3_tail);
				}
				j++;
			}

		} else {

		}

		/* free memory for next round */
		free(n1);
		free(n2);
		//free(n_n1);
		//free(n_n2);

	}




	cpu.r1_head = free_list(cpu.r1_head);
	cpu.r2_head = free_list(cpu.r2_head);
	cpu.r3_head = free_list(cpu.r3_head);

	return 0;
}

/**Adds two binary strings
* @param a first binary string
* @param b second binary string
* @param len length of string
* @return result third sting holding result of addition
*/
char *addBinary(char *a, char *b, int len)
{

        char *result = NULL;

        int s = 0;

        // Travers both strings starting
        // from last characters
        int i = len - 1, j = len - 1;
        while (i >= 0 || j >= 0 || s == 1)
        {

            s += ((i >= 0)? a[i] - '0': 0);
            s += ((j >= 0)? b[j] - '0': 0);

            result = (char)(s % 2 + '0') + result;

            s /= 2;

            i--; j--;
        }
	return result;
}

char *subBinary(char *a, char *b, int len)
{
	/*int a;
	int b;
	int c = 1;
	if(b == 1) {
		b = 0;
	} else {
		b = 1;
	}
	//addition(a , b);
	*/
	return a;

}

int overflow();

int carry_out();

int signflag();

int parity();

int zeroflag();

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


/** Creates node
 * @return void
 */

struct bit_t *create_node(void)
{
	struct bit_t *node;

	if (!(node = malloc(sizeof(struct bit_t)))) {
	end_prog(ENOMEM);
	}

	return node;
}

/** Sets up new node to be indexed
 * @param  n data to be entered in node
 * @return node
 */

struct bit_t *new_node(char *n)
{
	struct bit_t *node;

        node = create_node();

	/* just have pointers in structure so need to allocate space */
	node->n = malloc((strlen(n) + 1) * sizeof(char));
	if (!node->n) {
		end_prog(ENOMEM);
	}
	strcpy(node->n, n);

 	node->next = NULL;
	node->prev = NULL;

	return node;
}

/** Declares an error when malloc fails
 * @param err value to declare error
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

/** Prints list of nodes
 * @return void
 */

void print_list(struct bit_t *head)
{

	for ( ; head != NULL; head = head->next)
		print_node(head);

}

/** Prints single node
 * @return void
 */
void print_node(struct bit_t *node)
{
	printf("%s\n", node->n);

}

/** Adds node to head of list
 * @param head head of list
 * @param node node to be assigned to head
 * @param tail tail of list
 * @return new head
 */

struct bit_t *add_front(struct bit_t *head, struct bit_t *node, struct bit_t *tail)
{

	if (head == NULL) {
		head = node;
		tail = node;
	} else {
		node->next = head;
		(head)->prev = node;
		head = node;
	}

	return node;
}

/** Frees linked list
 * @param head head of list
 * @return null head
 */

struct bit_t *free_list(struct bit_t *head)
{
	struct bit_t *tmp = head;

	while(head) {
		head = head->next;
		/* must first free the strings */
		free(tmp->n);
		free(tmp);
		tmp = head;
	}

	return (head = NULL);

}

/** counts number of nodes
 * @param head head of list
 * @return count
 */

int count_nodes(struct bit_t *head)
{
	int count = 0;

	for( ; head != NULL; head = head->next)
		count++;

	return count;
}

/* trim off whitespace from the right */
/** Trims whitespace at end of string
 * @param s string to be edited
 */

void rstrip(char *s)
{
        int len = strlen(s) - 1;

        while (s[len] == 0x20 || s[len] == '\t' || s[len] == '\n' || s[len] == '\f' || s[len] == '\r' || s[len] == '\v')
                s[len--] = '\0';
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define LEN 128

/* use data from file */
/* run as ./bruce4 < data */
/* introduce strtok */


struct node_t {

	char *artist;
	char *title;
	int year;

	struct node_t *next;
};

void end_prog(int err)
{
	switch(err) {
	case ENOMEM:
		printf("malloc failed\n");
		/* errno.h has standard error codes */
		exit(ENOMEM);
	}
}

void print_node(struct node_t *node)
{
	printf("Artist: %s\n", node->artist);
	printf("Title: %s\n", node->title);
	printf("Year: %d\n\n", node->year);
}

void print_list(struct node_t *head)
{

	for ( ; head != NULL; head = head->next)
		print_node(head);

}

struct node_t *create_node(void)
{
	struct node_t *node;

	if (!(node = malloc(sizeof(struct node_t)))) {
		end_prog(ENOMEM);
	}

        return node;
}


/* create a new node */
/* year is now a string */
struct node_t *new_node(char *artist, char *title, char *year)
{
	struct node_t *node;

        node = create_node();
	//if (!(node = malloc(sizeof(struct node_t)))) {
	//	end_prog(ENOMEM);
	//}

	/* just have pointers in structure so need to allocate space */
	node->artist = malloc((strlen(artist) + 1) * sizeof(char));
	if (!node->artist) {
		end_prog(ENOMEM);
	}
	strcpy(node->artist, artist);

	node->title = malloc((strlen(title) + 1) * sizeof(char));
	if (!node->title) {
		end_prog(ENOMEM);
	}
	strcpy(node->title, title);

	node->year = atoi(year);

 	node->next = NULL;

	return node;
}

/* add node at the head of the list */
struct node_t *add_front(struct node_t *head, struct node_t *node)
{
	node->next = head;
	return node;
}

/* add to end of the ls */
struct node_t *add_end(struct node_t *head, struct node_t *node)
{
	struct node_t *p;

	if (head == NULL)
		return node;

	/* traverse the list find the end */
	for(p = head; p->next != NULL; p = p->next)
		;

	p->next = node;

	return head;

}

struct node_t *free_list(struct node_t *head)
{
	struct node_t *tmp = head;

	while(head) {
		head = head->next;
		/* must first free the strings */
		free(tmp->artist);
		free(tmp->title);
		free(tmp);
		tmp = head;
	}

	return (head = NULL);

}

struct node_t *search_list(struct node_t *head, char *artist)
{
	for( ; head != NULL; head = head->next)
		if (strcmp(artist, head->artist) == 0)
			return head;

	return NULL;
}

int count_nodes(struct node_t *head)
{
	int count = 0;

	for( ; head != NULL; head = head->next)
		count++;

	return count;
}

char *get_data(char *s)
{
	char *t = malloc((strlen(s) + 1) * sizeof(char));
	if (!t)
		end_prog(ENOMEM);
	return strncpy(t, s, strlen(s) + 1);
}


/* trim off whitespace from the right */
void rstrip(char *s)
{
        int len = strlen(s) - 1;

        while (s[len] == 0x20 || s[len] == '\t' || s[len] == '\n' || s[len] == '\f' || s[len] == '\r' || s[len] == '\v')
                s[len--] = '\0';
}


int main(void)
{
	char buf[LEN];
	char *s, *artist, *title, *year;

	struct node_t *head = NULL, *node = NULL, *tail = NULL;

	/* grab data from file */
	while(fgets(buf, LEN, stdin)) {
		/* remove new line in buf */
		rstrip(buf);

		/* split string on | */
		s = strtok(buf, "|");
		artist = get_data(s);

		s = strtok(NULL, "|");
		title = get_data(s);

		s = strtok(NULL, "|");
		year = get_data(s);

                /* what type of list is this? */
		head = add_front(head, new_node(artist, title, year));

		/* free memory for next round */
		free(artist);
		free(title);
		free(year);
	}

	print_list(head);
	printf("num_nodes = %d\n\n", count_nodes(head));

	node = search_list(head, "Elvis Presley");
	if (node) {
		printf("found record\n");
		print_node(node);
	}
	else
		printf("record not found\n");

	head = free_list(head);

	return 0;
}

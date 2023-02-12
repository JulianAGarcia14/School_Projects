#ifndef _STACK_H_
#define _STACK_H_

/* incomplete type */
typedef struct stack_t *stack;

/* create a new stack, have to call this first */
stack new_stack(void);

/* data is the user's data, whatever it is you want to push */
void push(stack stk, void *data);

/* return a void * to user's data
* user resposible to free any allocs involving 
* the data
*/
void *pop(stack stk); 

/* return the data at the top of the stack 
 * do not pop */
void *peek(stack stk);

/* free all nodes in the stack */
void free_stack(stack stk);

/* return 1 is stack is empty, 0 otherwise */
int is_stack_empty(stack stk);

/* returns the number of items on the stack */
int stack_count(stack stk);

#endif

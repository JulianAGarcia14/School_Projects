#include "stack.h"
#include <stdlib.h>
#include <assert.h>

struct stack_t {
        int count;
        struct node_t {
                void *data;
                struct node_t *next;
        } *head;
};




#ifndef STACK_H
#define STACK_H


struct node {
	void* data;
	struct node* next;
};
typedef struct node  node_t;


typedef struct {
  node_t* top;
} tstack_t;


// creates a new stack
tstack_t* stack_create();


// pushes a given item to the stack
// Pre condition: stack is not empty
void stack_push(tstack_t* s, void* item);


// pops the top element from the stack
// Pre condition: stack is not empty
void* stack_pop(tstack_t* s);


// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(tstack_t* s);


// releases the memory used by the stack
void stack_free(tstack_t* s);

#endif

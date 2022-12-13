#ifndef STACK_H
#define STACK_H


struct node {
	void* data;
	struct node* next;
};
typedef struct node  node_t;


typedef struct {
  node_t* top;
} stack_t; 


// creates a new stack
stack_t* stack_create();


// pushes a given item to the stack
// Pre condition: stack is not empty
void stack_push(stack_t* s, void* item);


// pops the top element from the stack
// Pre condition: stack is not empty
void* stack_pop(stack_t* s);


// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack_t* s);


// releases the memory used by the stack
void stack_free(stack_t* s);

#endif

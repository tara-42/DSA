#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


// creates a new stack
stack_t* stack_create()
{
  stack_t* s = (stack_t*) malloc(sizeof(stack_t));
  s->top = NULL;
  return s;
}

// pushes a given item to the stack
// Pre condition: stack is not empty
void stack_push(stack_t* s, void* item)
{
  node_t* newTop = (node_t*) malloc(sizeof(node_t));
  newTop->data = item;
  newTop->next = s->top;
  s->top = newTop;
}

// pops the top element from the stack
// Pre condition: stack is not empty
void* stack_pop(stack_t* s)
{
  void* ret = s->top->data;
  node_t* prevTop = s->top;
  s->top = prevTop->next;
  free(prevTop);
  return ret;
}

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack_t* s)
{
    return (s->top == NULL);
}

void stack_free(stack_t* s) 
{
  while (s->top)
  {
    node_t* prevTop = s->top;
    s->top = prevTop->next;
    free(prevTop);
  }
  free(s);
}

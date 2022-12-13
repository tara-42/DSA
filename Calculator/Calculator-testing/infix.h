#ifndef INFIX_H
#define INFIX_H


int find_operator(char** expression, int n_tokens);

// gets an array of tokens representing an arithmetic expression in infix notation
// outputs the value of the expression.
int infix_eval_tokens(char** str, int n_tokens);


// gets a string representing an arithmetic expression in infix notation
// outputs the value of the expression.
int infix_eval(char* arith_expr);


#endif
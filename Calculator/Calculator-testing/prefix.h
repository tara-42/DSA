#ifndef PREFIX_H
#define PREFIX_H

// gets an array of tokens representing an arithmetic expression in the prefix notation
// returns the evaluation of the expression
int prefix_eval_token(char** prefix_expr, int n_tokens);


// gets a string representing an arithmetic expression in prefix notation
// and evaluates the corresponding expression.
int prefix_eval(char* prefix_expr);

#endif
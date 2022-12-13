#ifndef PARSE_H
#define PARSE_H


// gets a string a counts the number of tokens in the strings.
// The tokens are separated by a single space
// There are no spaces before the first token, and no spaces after the last token
int count_tokens(char* str);


// gets a string and a number of tokens from count_tokens(str)
// returns an array of tokens
char** get_tokens(char* str, int n_tokens);


// retuns 1 if str is an operator, i.e., "+", "-", "*", "/"
// returns 0 otherwise
int is_operator(char* str);


// retuns 1 if str is a number
// returns 0 otherwise
int is_number(char* str);


// converts a non-negative int to string
char* num_to_str(unsigned int num);

#endif

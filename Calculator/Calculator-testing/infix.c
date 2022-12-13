#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "infix.h"
#include "parse.h"

int find_operator(char** expression, int n_tokens) {
  if (n_tokens <= 1)
    return -1;

  if (*(expression[0]) != '(')
  {
    printf("wrong!");
    return -1;
  }

  int count = 0;
  for (int j = 1; ; j++) {
    if (*(expression[j]) == '(')
      count++;
    if (*(expression[j]) == ')')
      count--;
    if (count == 0)
      return j+1;
  } 
}

int infix_eval_tokens(char** expression, int n_tokens) {
//  printf("eval_tokens: %s :: %d\n", expression[0], n_tokens);
  if (n_tokens == 1)
  {
    return atoi(expression[0]);
  }
  else {
    int op = find_operator(expression, n_tokens);
    int term1 = infix_eval_tokens(expression+1, op-1);
    int term2 = infix_eval_tokens(expression+op+1, n_tokens-op-2);
    
   switch(expression[op][0]) {
      case '+' :
 //        printf("%d + %d = %d\n", term1, term2, term1 + term2);
         return term1 + term2;
      case '-' :
//         printf("%d - %d = %d\n", term1, term2, term1 - term2);
         return term1 - term2;
      case '*' :
//         printf("%d * %d = %d\n", term1, term2, term1 * term2);
         return term1 * term2;
      case '/' :
//         printf("%d / %d = %d\n", term1, term2, term1 / term2);
         return term1 / term2;
      default :
        return -9999;
    }
  }
}

int infix_eval(char* expression) {
  int n_tokens = count_tokens(expression);
  char** tokens = get_tokens(expression, n_tokens);
  int result = infix_eval_tokens(tokens, n_tokens);
 
  for (int i=0; i < n_tokens; i++)
    free(tokens[i]);
  free(tokens);
 
  return result;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "stack.h"

#include "prefix.h"

int prefix_eval_token(char** prefix_expr, int n_tokens)
{
  int term1, term2;
  stack_t* s = stack_create();
  for (int i = n_tokens-1; i >= 0; i--)
  {
    if (is_number(prefix_expr[i]))
      stack_push(s, prefix_expr[i]);
    else // infix_expr[i] is an operator
    {
      term1 = atoi((char*) stack_pop(s));
      term2 = atoi((char*) stack_pop(s));
      switch(prefix_expr[i][0]) {
        case '+' :
//          printf("push %d + %d = %d\n", term1, term2, term1 + term2);
          stack_push(s, num_to_str(term1 + term2));
          break;
        case '-' :
//          printf("push %d - %d = %d\n", term1, term2, term1 - term2);
          stack_push(s, num_to_str(term1 - term2));
          break;
        case '*' :
//          printf("push %d * %d = %d\n", term1, term2, term1 * term2);
          stack_push(s, num_to_str(term1 * term2));
          break;
        case '/' :
//          printf("push %d / %d = %d\n", term1, term2, term1 / term2);
          stack_push(s, num_to_str(term1 / term2));
          break;
        default :
          break;
      }
    }
  }
  int result = atoi((char*) stack_pop(s));
  stack_free(s);
  return result;
}

int prefix_eval(char* prefix_expr) {
  int n_tokens = count_tokens(prefix_expr);
  char** tokens = get_tokens(prefix_expr, n_tokens);
  int result = prefix_eval_token(tokens, n_tokens);

  for (int i=0; i < n_tokens; i++)
    free(tokens[i]);
  free(tokens);

  return result;
}

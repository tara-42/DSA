#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prefix.h"
#include "stack.h"
#include "parse.h"

//9 - gets an array of tokens representing an arithmetic expression in
//the prefix notation, and computes the evaluation of the expression
int prefix_eval_token(char** prefix_expr, int n_tokens)
{

  tstack_t* s = stack_create();

  for (int i=n_tokens-1; i>=0; i--){

    if (is_number(prefix_expr[i]) == 1) {
      stack_push(s, atoi(prefix_expr[i]));
    }
    else {

        int operand_2 = stack_pop(s);

        int operand_1 = stack_pop(s);

        if(strcmp(prefix_expr[i], "+") == 0 )
          stack_push(s, operand_1 + operand_2);

          if(strcmp(prefix_expr[i], "*") == 0 )
            stack_push(s, operand_1 * operand_2);

            if(strcmp(prefix_expr[i], "/") == 0 )
              stack_push(s, operand_1 / operand_2);

              if(strcmp(prefix_expr[i], "-") == 0 )
                stack_push(s, operand_1 - operand_2);

      }
  }

  return stack_pop(s);
  }

//10 - Use the functions in part 1 and prefix_eval to write a function that gets a string
//representing an arithmetic expression in prefix notation and evaluates the
//corresponding expression
int prefix_eval(char* prefix_expr) {
  // implement me
    int count = count_tokens(prefix_expr);

    char** tokens = get_tokens(prefix_expr, count);

    for(int i = 0; i < count; i++){

    int output = prefix_eval_token(tokens, count);
    }

  return output;
}

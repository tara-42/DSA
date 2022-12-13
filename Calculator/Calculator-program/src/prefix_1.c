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

  printf("---------------\n");
  for(int i = 0; i < n_tokens; i++)
    printf("token[%d] is: %s\n", i, prefix_expr[i]);

  printf("----- token at index 3 is: %s\n", prefix_expr[3]);

  tstack_t* s= stack_create();
  //tstack_t* s = (tstack_t*) malloc(sizeof(tstack_t));
  //s->top = NULL;
  printf("%p", s);
  printf("%p", prefix_expr);
  //tstack_t* s = stack_create();


  printf("++++++++++++++++\n");
  for(int i = 0; i < n_tokens; i++)
    printf("token[%d] is: %s\n", i, prefix_expr[i]);




  printf("------ token at index 3 is: %s\n", prefix_expr[3]);


  for (int i=n_tokens-1; i>=0; i--){
    printf("token at index 3 is: %s\n", prefix_expr[3]);
    printf("current token at index %d is : %s\n", i, prefix_expr[i]);
    if (is_number(prefix_expr[i]) == 1) {

      printf("token at index 3 is: %s\n", prefix_expr[3]);
      printf("we are pushing %d\n",  atoi(prefix_expr[i]));
      stack_push(s, atoi(prefix_expr[i]));
      printf("token at index 3 is: %s\n", prefix_expr[3]);

    }
    else {
        printf("current operator: %s\n", prefix_expr[i]);
        printf("debug1\n");
        int operand_2 = stack_pop(s);
        printf("we are poping %d\n", operand_2);
        printf("debug2\n");
        int operand_1 = stack_pop(s);
        printf("we are poping %d\n", operand_1);
        printf("debug3\n");
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

  printf("count: %d\n", count);

  char** tokens = get_tokens(prefix_expr, count);

  for(int i = 0; i < count; i++)
    printf("token[%d] is: %s\n", i, tokens[i]);

  int output = prefix_eval_token(tokens, count);


  return output;
}

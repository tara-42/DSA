#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "infix.h"

int find_operator(char** expression, int n_tokens)
{
  // implement me

  int depth = 0;

  int last_operator_index = -1;
  int last_operator_depth = -1;

  for (int i=0; i<n_tokens; i++)
  {
  if (expression[i] == '('){
    depth++;
  }
  else if (expression[i] == ')'){
    depth--;
  }
  if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || expression[i] == '/')
  {
      if (last_operator_index == -1){
      last_operator_depth = depth;
      last_operator_index = i;
      }

      if (last_operator_index != -1)
      {
        if (depth < last_operator_depth)
        {
        last_operator_depth = depth;
        last_operator_index = i;
        }
      }
  }

  return last_operator_index;
  }
}

int infix_eval_tokens(char** expression, int n_tokens){
  // implement me
  int last_operator_index = find_operator(expression, n_tokens);

  //if last_operator_index == -1 // no oper found base case
  //return number;
  //if last_operator_index = -1 then return that number


  char** s2 = malloc(sizeof(char*)*(n_tokens-last_operator_index-1));
  char** s1 = malloc(sizeof(char*)*(last_operator_index));

  memcpy(s2, expression+last_operator_index+1, (n_tokens-last_operator_index-1));
  memcpy(s1, expression, (last_operator_index));

  int result1 = infix_eval_tokens(s1, (last_operator_index));
  int result2 = infix_eval_tokens(s2, (n_tokens-last_operator_index-1));
  int output;
  int i;

  if (expression[i] == '*' ){
  output = s1*s2;
  }

  if (expression[i] == '+'){
  output = s1+s2;
  }

  if( expression[i] == '-' ){
  output = s1-s2;
  }

  if (expression[i] == '/'){
  output = s1/s2;
  }

  //void *memcpy(void *str1, const void *str2, size_t n);
  return output;

}


int infix_eval(char* expression)
{
  // implement me
  return 0;
}

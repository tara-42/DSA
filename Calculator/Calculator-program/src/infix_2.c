#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "infix.h"
#include "parse.h"

int find_operator(char** expression, int n_tokens)
{
  // implement me

  int depth = 0;

  //start at -1
  int last_operator_index = -1;
  int last_operator_depth = -1;

  //loop through the tokens
  for (int i=0; i<n_tokens; i++)
  {
  //increment depth when open (
      if (strcmp(expression[i], "(") == 0){
        depth++;
      }

      //decrement depth when close )
      else if (strcmp(expression[i], ")") == 0){
        depth--;
      }

      //figure out what operator you are working with
        if (is_operator(expression[i])){
        //if last_operator_index == -1 // no operator found -> base case nonstarter
        //return number - empty
        //if last_operator_index != -1
        //then return that number: last_operator_depth=i

          if (last_operator_index == -1){
          last_operator_depth = depth;
          last_operator_index = i;
          }

          if (last_operator_index != -1)
          {
            //??? when the depth is less than the operand index (we made them equal before) maybe != instead of <
            if (depth < last_operator_depth)
            {
            last_operator_depth = depth;
            last_operator_index = i;
            }
          }
      }

  }
  return last_operator_index;

}

//task 7
int infix_eval_tokens(char** expression, int n_tokens){
  // implement me

  //get the operator starting from deepest level
  int i = find_operator(expression, n_tokens);

  if (i == -1){
    for (int j=0; j<n_tokens; j++){
      if(is_number(expression[j]))
        return atoi(expression[j]);
    }
  }

  char** s1 = expression;
  char** s2 = expression + i + 1;

   int result1 = infix_eval_tokens(s1, i);
   int result2 = infix_eval_tokens(s2, n_tokens-i-1);

   int output = -1;

  //??? should this be i=last_operator_inde
    if (strcmp(expression[i], "*") == 0  ){
      output = result1 * result2;
      }

      if (strcmp(expression[i], "+") == 0){
      output = result1 + result2;
      }

      if(strcmp(expression[i], "-") == 0  ){
      output = result1 - result2;
      }

      if (strcmp(expression[i], "/") == 0  ){
      output = result1 / result2;
      }

  //void *memcpy(void *str1, const void *str2, size_t n); ????? compiler doesn't like this
  return output;

}

//task 8 use functions from part 1
//convert array of chars to an array of strings
//and then use the infix eval token function to solve the expression
int infix_eval(char* expression)
{

  int count = count_tokens(expression);
  char** tokens = get_tokens(expression, count);
  int output = infix_eval_tokens(tokens, count);
  return output;

}

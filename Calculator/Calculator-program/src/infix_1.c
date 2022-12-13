#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "infix.h"

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
  if (expression[i] == '('){
    depth++;
  }

  //decrement depth when close )
  else if (expression[i] == ')'){
    depth--;
  }

  //figure out what operator you are working with
  if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || expression[i] == '/')
  {
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

  return last_operator_index;
  }
}

//task 7
int infix_eval_tokens(char** expression, int n_tokens){
  // implement me

  //get the operator starting from deepest level
  int last_operator_index = find_operator(expression, n_tokens);

  //allocate memory for tokens, split into statement 1 and 2
  char** s2 = malloc(sizeof(char*)*(n_tokens-last_operator_index-1));
  //??? should this be last_operator_index+1
  char** s1 = malloc(sizeof(char*)*(last_operator_index));

  //copy s1 and s2
  //copy destination is s2, source is (expression+position of last operator+1, bytes to be copied)
  memcpy(s2, expression+last_operator_index+1, (n_tokens-last_operator_index-1));
  //??? copy destination is s1, source is (last operator, bytes to be copied is all?)
  memcpy(s1, expression, (last_operator_index));


  //rescursively evaluate result1 from evaluating statement 1 with corresponding token
  int result1 = infix_eval_tokens(s1, (last_operator_index));

  //rescursively evaluate result2 from stmt 2 and corresponding token
  int result2 = infix_eval_tokens(s2, (n_tokens-last_operator_index-1));
  int output;

  //??? should this be i=last_operator_index
  int i=0;

      if (expression[i] == '*' ){
      output = result1 * result2;
      }

      if (expression[i] == '+'){
      output = result1 + result2;
      }

      if( expression[i] == '-' ){
      output = result1 - result2;
      }

      if (expression[i] == '/'){
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
  // implement me


  //make a string
  char* string[] = malloc(sizeof(char*)*expression);

  int n_tokens = sizeof(expression);

  //copy everything from expression to string (convert array of chars to array of strings)
  //char * strncpy(char * destination, const char * source, size_t num);
  strncpy(string, expression, n_tokens);

  string[n_tokens] = '\0';

  int output;
  //??? n_tokens
  output = infix_eval_tokens(string, n_tokens);

  return output;
}


/*str strn_array;
int i = 0;
int output;
  while (expression != NULL){
      strn_array[i] = expression;
      i++;
  }*/

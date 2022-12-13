#include <stdio.h>
#include <stdlib.h>

#include "infix.h"
#include "prefix.h"
#include "parse.h"


int main()
{
  //char string[] = "/ 25 5";
  //printf("%d\n", count_tokens(string));

  /*char** output = get_tokens(string, 4);

 for (int i=0; i< 4; i++){
    printf("%s\n ",output[i]);
  }*/


  /*char string[] = "123";
  printf("%d \n", is_operator(string));*/

/*char string [] = "abc";
printf("%d", is_number(string));*/

  /*char* ptr = num_to_str(12);
  printf("%s\n", ptr);*/

  /*char* string[9] = {"(", "(", "1", "+", "2", ")", "+", "1", ")"};

  int operator =  find_operator(string, 9);
  printf("%d\n", operator);*/

  /*char* string[9] = {"(", "(", "1", "+", "2", ")", "*", "2", ")"};
  int output = infix_eval_tokens(string, 9);
  printf("%d\n", output);*/

  //char s1[100] = "( ( 10 + 6 ) / ( ( 3 + 7 ) - ( 2 + 4 ) ) )";
  //char s[] = "( ( 1 + 2 ) * 4 ) ";
  //printf("ANSWER = %d\n", infix_eval(s1));

  char* string[] = {"+", "-", "1", "3", "4"};
  printf("%d\n", prefix_eval_token(string, 5));

  /*char string[100] = "+ - 1 3 4";
  int result = prefix_eval(string);
  printf("%d\n", result);*/

  //char s2[100] = "- / + 15 13 - 5 1 + 2 4";
  //printf("ANSWER = %d\n", prefix_eval(s2));
}

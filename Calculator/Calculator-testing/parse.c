#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"


int count_tokens(char* str) {
  int count = 0;
  while (*str)
  {
    if (*str ==' ')
      count++;
    str++;
  }
  return count+1;
}


char** get_tokens(char* str, int n_tokens) {

  char** tokens = (char**) malloc(n_tokens*sizeof(char*));
  
  char* start_token;
  int token_len;
  for (int i = 0; i < n_tokens; i++)
  {
    start_token = str;
    token_len = 0;
    while ((*str != '\0') && (*str != ' '))
    {
      str++;
      token_len++;
    }
    str++;
    tokens[i] = (char*) malloc((token_len+1)*sizeof(char)); // remember +1 for the '\0'
    strncpy(tokens[i], start_token, token_len);
    (tokens[i])[token_len] = '\0';
  }
  return tokens; 
}

int is_operator(char* str) {
  return (str[1] == '\0') && (*str == '+' || *str == '-' || *str == '*' || *str == '/');
}

int is_number(char* str) {
  if (strlen(str) <= 0)
    return 0;
  int  i = 0;
  while (str[i] != '\0')  {
    if (str[i] >='0' && str[i] <= '9')
      i++;
    else
      return 0;
  }

	return 1;
}

// converts a non-negative int to string
char* num_to_str(unsigned int num) {
  int digit = 3;
  char c = '0' + digit;
  char* ret = (char*) malloc (3*sizeof(char));
  if (num <= 9)
  {
    ret[0] = '0' + num;
    ret[1] = 0;
  }
  else
  {
    ret[0] = '0' + (num / 10);
    ret[1] = '0' + num % 10;
    ret[2] = '\0';
  }
  return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

//1 gets a string and counts the number of tokens in str .
int count_tokens( char* str)
{
  char* token;

  char* copy_str = malloc(sizeof(char) * strlen(str));
  strcpy(copy_str, str);

  token = strtok(copy_str, " ");
  int count=0;
  while (token != NULL) {
    count++;
    token = strtok(NULL, " ");
  }

  //free(copy_str);
  return count;
}

// 2 - gets a string, and the number of tokens obtained in count_tokens
//and returns an array of strings,
char** get_tokens(char* str, int n_tokens) {
    char** tokens = malloc(sizeof(char*)*n_tokens);

    char* copy_str = malloc(sizeof(char) * strlen(str));
    strcpy(copy_str, str);

    char* token = strtok(copy_str, " " );

    int i = 0;

    while (token != NULL ) {
      tokens[i] = malloc(sizeof(char) * strlen(token));
      strcpy(tokens[i], token);
      token = strtok(NULL, " ");
      i++;
     }

     free(copy_str);
     return tokens;
}

//3 - gets a string and checks if it is an arithmetic operator
int is_operator( char * str)
{
  int i=0;
  for (i=0; i<strlen(str); i++)
  {
    if (str[i] == '+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
    return 1;
  }
  return 0;
}

//4 - hecks if a given string is a non-negative integer,
int is_number( char * str) {
  int val = atoi(str);

  if (val == 0){
    return 0;
  }

  else{
    return 1;
  }
}

//5 - gets a non-negative int and return a string containing this int
char * num_to_str( unsigned int num){

  char* string = malloc (sizeof(char)*2);

  sprintf(string, "%d", num);

  return string;
}

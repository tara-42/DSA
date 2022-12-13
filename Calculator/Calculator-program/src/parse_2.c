#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

//1 gets a string and counts the number of tokens in str .
int count_tokens( char * str)
{

  int i;
  int count=0;
  int n  = strlen(str);

  //start loop
  for (i=1; i<n; i++)
  {
      if (str[i] == ' ' && str[i-1] != ' ')
      {
        count ++;
      }
  }

  if (str[n-1] != ' ')
  {
    count ++;
  }
  return count;
  }

// 2 - gets a string, and the number of tokens obtained in count_tokens
//and returns an array of strings,
char** get_tokens(char* str, int n_tokens) {
    char** tokens = malloc(sizeof(char*)*n_tokens);
    tokens = strtok(str, ' ' );
    int count=0;
    while (tokens != NULL ) {
        printf( " %s\n", tokens);

        tokens = strtok(NULL, ' ');
        tokens [count] == tokens;
        count++;

     }
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

  int n;
  if (num <10){
  n = 1;
  }
  else {
    (num >= 10);
  n=2;
  }

  char* array = malloc(sizeof(char)*n);

  for (int i=n-1; i>=0; i--)
  {
    array[i] = num % 10;
    num = num/10;

  }

  return array;

}

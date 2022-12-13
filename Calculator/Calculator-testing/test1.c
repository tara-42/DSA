#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"



char** ig_get_tokens(char* str, int n_tokens) {

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
    tokens[i] = (char*) malloc((token_len+1)*sizeof(char));
    strncpy(tokens[i], start_token, token_len);
    (tokens[i])[token_len] = '\0';
  }
  return tokens; 
}

int test1()
{
  int len = 5;
  char s[100] = "7 + 78 - 66";
  char** toks = get_tokens(s, len);

  int count = 0;


// Q1  - 6 points
int a = count_tokens(s);
      count += 6;
if (a != len)
    printf("!!!!!!!!!!!!!!! Q1 !!  %d != %d\n", a, len);


// Q2  - 15 points
  char** ig_toks =  ig_get_tokens(s, len);
  int flag = 1;
  for (int i = 0; i < len; i++)
  {
    if (strcmp(ig_toks[i], toks[i]) != 0)
    {
      flag = 0;
	printf("!!! %s  <><> %s \n", ig_toks[i], toks[i]);
    }
  }
  if (flag)
    count +=15;
  else
    printf("!!!!!!!!!!!!!!! Q2 !!\n");


// Q3  - 3 points
  if (is_operator("+") == 1)
    count +=1;
  else
    printf("!!!!!!!!!!!!!!! Q3 1 !!\n");
  if (is_operator("9") == 0)
    count +=1;
  else
    printf("!!!!!!!!!!!!!!! Q3 2 !!\n");
  if (is_operator("B") == 0)
    count +=1;
  else
    printf("!!!!!!!!!!!!!!! Q3 3 !!\n");


// Q4  - 8 points
  if (is_number("B") == 0)
    count +=1;
  else
    printf("!!!!!!!!!!!!!!! Q4 1 !!\n");

  if (is_number("9B") == 0)
    count +=2;
  else
    printf("!!!!!!!!!!!!!!! Q4 2 !!\n");

  if (is_number("9") == 1)
    count +=2;
  else
    printf("!!!!!!!!!!!!!!! Q4 3 !!\n");

  if (is_number("12") == 1)
    count +=3;
  else
    printf("!!!!!!!!!!!!!!! Q4 4 !!\n");


// Q5  - 8 points
  if (strcmp(num_to_str(1),"1") == 0)
    count +=4;
  else
    printf("!!!!!!!!!!!!!!! Q5 1 !!\n");
  if (strcmp(num_to_str(85),"85") == 0)
    count +=4;
  else
    printf("!!!!!!!!!!!!!!! Q5 2 !!\n");

  return count;
}

int main()
{

  printf("-------------------- PART1-PARSE -------------------\n");
  int count = 0;
  count +=test1();   printf("PART 1: count = %d\n", count);

 return 0;
}
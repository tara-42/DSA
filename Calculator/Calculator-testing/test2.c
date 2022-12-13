#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "infix.h"
//#include "prefix.h"



int test2()
{
  int count = 0;
  printf("!!!!!!!!!!!!!!! PART2 1 start...\n");
  char s1[100] = "( 8 + ( 41 - 12 ) )"; 
  if (infix_eval(s1) == 37)
{
    printf("!!!!!!!!!!!!!!! PART2 1 OK\n");
    count +=10;
}
  else
    printf("!!!!!!!!!!!!!!! PART2 1 !!, %d != 37\n", infix_eval(s1));

  printf("!!!!!!!!!!!!!!! PART2 2 start...\n");
  char s2[100] = "( ( 10 + 6 ) / ( ( 3 + 7 ) - ( 2 + 4 ) ) )"; 
  if (infix_eval(s2) == 4)
{
    printf("!!!!!!!!!!!!!!! PART2 2 OK\n");
    count +=10;
}
  else
    printf("!!!!!!!!!!!!!!! PART2 2 !!, %d != 4\n", infix_eval(s2));

  printf("!!!!!!!!!!!!!!! PART2 3 start...\n");
  char s3[100] = "( ( ( 18 + 1 ) + 1 ) * 1 )"; 
  if (infix_eval(s3) == 20)
{
    printf("!!!!!!!!!!!!!!! PART2 3 OK\n");
    count +=10;
}
  else
    printf("!!!!!!!!!!!!!!! PART2 3 !!, %d != 20\n", infix_eval(s3));


  return count;
}


int main()
{

  printf("-------------------- PART2-INFIX -------------------\n");
  int count = 0;
  count +=test2();   printf("PART 2: count = %d\n", count); // INFIX
 

 return 0;
}
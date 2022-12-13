#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
//#include "infix.h"
#include "prefix.h"



int test3()
{
  int count = 0;

  printf("!!!!!!!!!!!!!!! PART3 1 start...\n");
  char t1[100] = "- / + 15 13 - 5 1 + 2 2";
  if (prefix_eval(t1) == 3)
  {
    printf("!!!!!!!!!!!!!!! PART3 1 OK\n");
    count +=10;
  }
  else
    printf("!!!!!!!!!!!!!!! PART3 1 !!, %d != 3\n", prefix_eval(t1));

  printf("!!!!!!!!!!!!!!! PART3 2 start...\n");
  char t2[100] = "/ 25 5";
  if (prefix_eval(t2) == 5)
  {
    printf("!!!!!!!!!!!!!!! PART3 2 OK\n");
    count +=10;
  }
  else
    printf("!!!!!!!!!!!!!!! PART3 2 !!, %d != 5\n", prefix_eval(t2));

  printf("!!!!!!!!!!!!!!! PART3 3 start...\n");
  char t3[100] = "+ - 25 6 * 4 3";
  if (prefix_eval(t3) == 31)
  {
    printf("!!!!!!!!!!!!!!! PART3 3 OK\n");
    count +=10;
  }
  else
    printf("!!!!!!!!!!!!!!! PART3 3 !!, %d != 31\n", prefix_eval(t3));



  return count;
}

int main()
{

  printf("--------------------PART3-PREFIX --------------------\n");
  int count = 0;
//  count +=test1();   printf("PART 1: count = %d\n", count);
//  count +=test2();   printf("PART 2: count = %d\n", count);
  count +=test3();   printf("PART 3: count = %d\n", count); // PREFIX
 

 return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "infix.h"
#include "prefix.h"
#include "parse.h"


void testInfix(char* infix, int expectedResult)
{
    int countx = count_tokens(infix);
    char** arrayx = get_tokens(infix, countx);
    printf("%s\n", infix);
    printf("InfixEvalTokens(Expected=%d, Result=%d)\n", expectedResult, infix_eval_tokens(arrayx, countx));
    printf("InfixEval      (Expected=%d, Result=%d)\n\n", expectedResult, infix_eval(infix));
}

void testPrefix(char* prefix, int expectedResult)
{
    int countx = count_tokens(prefix);
    char** arrayx = get_tokens(prefix, countx);
    printf("%s\n", prefix);
    printf("PreEvalTokens(Expected=%d, Result=%d)\n", expectedResult, prefix_eval_token(arrayx, countx));
    printf("PrefixEval   (Expected=%d, Result=%d)\n\n", expectedResult, prefix_eval(prefix));
}

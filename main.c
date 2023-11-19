// gcc -Wall -O3 -o main main.c

#include "condition_check.h"

int main()
{
    const char * p = NULL;
    condition_check(p != NULL, return 1);

    return 0;
}

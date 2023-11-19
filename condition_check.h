#ifndef CONDITION_CHECK
#define CONDITION_CHECK

#include <stdio.h>

/* Custom macro, checks a condition and performs an action
 Rather like assert(), but it doesn't need to always call abort()
 Safety critical software can printf, or log, and return an error
 */
#define condition_check(condition, action) \
    do { \
        if (!(condition)) { \
            printf("condition_check: %s %s:%d\n", #condition, __FILE__, __LINE__); \
            action; \
        } \
    } while (0)

#endif

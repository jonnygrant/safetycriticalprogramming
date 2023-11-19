#ifndef CONDITION_CHECK
#define CONDITION_CHECK

#include <stdio.h>

/* Custom macro, checks a condition and performs an action
 Rather like assert(), but it doesn't need to always call abort()
 Safety critical software can printf, or log, and return an error
 */
#define _CHECK_HELPER(x) #x
#define _CHECK_LINE_STRING(x) _CHECK_HELPER(x)
#define condition_check(condition, action) \
    do { \
        if (!(condition)) { \
            printf("condition_check: (" #condition ") " __FILE__ ":" _CHECK_LINE_STRING(__LINE__) "\n"); \
            action; \
        } \
    } while (0)

#endif

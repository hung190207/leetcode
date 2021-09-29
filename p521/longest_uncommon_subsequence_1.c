#include <stdio.h>

// Don't using solution in leetcode to get 100%

int findLUSlength(char* a, char* b) {
    return strcmp(a, b) ? (*a = strlen(a)) > (*b = strlen(b)) ? *a : *b : -1;
}
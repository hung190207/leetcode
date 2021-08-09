#include <stdio.h>
//     i
// a b c
// j
//Runtime: 48 ms, faster than 74.91% of C online submissions for Reverse String.

char* reverseString(char* s, int size) {
    int i = 0;
    int j = size - 1;

    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s;
}
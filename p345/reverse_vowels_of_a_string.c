#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Runtime: 4 ms, faster than 75.59% of C online submissions for Reverse Vowels
// of a String.

char* reverseVowels(char* s) {
    if (!s) {
        return NULL;
    }

    int end = strlen(s);
    for (int i = 0; i < end; i++) {
        // About {strchr} func : Vietnamese:
        //                       https://quantrimang.com/ham-strchr-trong-c-158008
        //                       English:
        //                       https://www.tutorialspoint.com/c_standard_library/c_function_strchr.htm
        // You can use if instead of strchr.

        if (strchr("aeiouAEIOU", s[i])) {
            while (--end > i && !strchr("aeiouAEIOU", s[end]))
                ;
            if (end <= i) {
                break;
            }

            char c = s[i];
            s[i] = s[end];
            s[end] = c;
        }
    }
    return s;
}

void test(char* s, char* wanted) {
    int size = strlen(s);
    char* copy = (char*)malloc(size + 1);
    strcpy(copy, s);
    reverseVowels(copy);

    for (int i = 0; i < size; i++) {
        if (copy[i] != wanted[i]) {
            printf("ERROR: input=%s, actual=%s but wanted=%s\n", s, copy,
                   wanted);
            return;
        }
    }
}

int main() { test("hello", "holle"); }
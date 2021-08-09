#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://leetcode.com/problems/reverse-string/

//     i
// a b c
// j
// Runtime: 48 ms, faster than 74.91% of C online submissions for Reverse
// String.

void reverseString(char* s, int size) {
    int i = 0;
    int j = size - 1;

    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void test(char* s, int size, char* wanted) {
    char* copy = (char*)malloc(size + 1);
    strcpy(copy, s);
    reverseString(copy, size);

    for (int i = 0; i < size; i++) {
        if (copy[i] != wanted[i]) {
            printf("ERROR: input=%s, actual=%s but wanted=%s\n", s, copy,
                   wanted);
            return;
        }
    }
}

int main() {
    test("abc", 3, "cba");
    test("hello", 5, "olleh");
    test("nguyen ngoc hung", 16, "gnuh cogn neyugn");
}
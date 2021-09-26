#include <stdbool.h>
#include <stdio.h>

#include "../lib/bool.h"
#include "../lib/str.h"

bool isAnagram(char* s, char* t) {
    int i;
    int a;
    int b;
    int arr[26] = {0};
    a = strlen(s);
    b = strlen(t);
    if (a != b) {
        return false;
    }
    for (i = 0; i < a; i++) {
        arr[s[i] - 'a'] += 1;
        arr[t[i] - 'a'] -= 1;
    }
    for (i = 0; i < 26; i++) {
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}

void test(char* s, char* t, char wanted) {
    char actual = isAnagram(s, t);
    if (wanted != actual) {
        printf("ERROR : wanted = %s but actual = %s\n", bool2str(wanted),
               bool2str(actual));
    }
}

int main() {
    test("anagram", "nagaram", true);
    test("rat", "car", false);
}
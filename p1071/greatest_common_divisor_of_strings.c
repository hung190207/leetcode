#include <stdio.h>
#include <stdlib.h>

#include "../lib/str.h"

char* gcdOfStrings(char* str1, char* str2) {
    int size_1 = strlen(str1);
    int size_2 = strlen(str2);

    if (size_1 < size_2) {
        return gcdOfStrings(str2, str1);
    }

    for (int i = 0; i < size_2; i++) {
        if (str1[i] != str2[i]) {
            return "";
        }

        if (size_1 == size_2) {
            return str1;
        }
    }

    return gcdOfStrings(str1 + size_2, str2);
}

void test(char* str1, char* str2, char* wanted) {
    char* actual = gcdOfStrings(str1, str2);
    compare(wanted,actual);
}

int main(){
    test("ABCABC","ABC","ABC");
    test("ABABAB","ABAB","AB");
    test("LEET","CODE","");
    test("ABCDEF","ABC","");
}
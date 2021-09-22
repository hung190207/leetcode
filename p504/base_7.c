#include <stdio.h>

#include "../lib/str.h"

// TODO : Solve it without helping from solutions . 

char* convertToBase7(int num) {
    char negative = 0;
    if (num < 0) {
        negative = 1;
        num = -num;
    }

    char temp[32];
    char len = 0;

    do {
        temp[len] = num % 7 + '0';
        len++;
        num = num / 7;
    } while (num);

    char index = 0;
    char* result = malloc(len + negative + 1);

    if (negative) {
        result[index] = '-';
        index++;
    }

    for (int i = len - 1; i > -1; --i) {
        result[index] = temp[i];
        index++;
    }

    result[index] = '\0';

    return result;
}

void test(int n, char* wanted) {
    char* actual = convertToBase7(n);
    compare(wanted, actual);
}

int main() {
    test(100, "202");
    test(-7, "-10");
}
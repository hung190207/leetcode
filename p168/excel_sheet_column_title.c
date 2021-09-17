#include <stdio.h>
#include <stdlib.h>

#include "../lib/str.h"

char *convertToTitle(int n) {
    if (!n) {
        return NULL;
    }
    int a;
    int count = 0;
    char *b = malloc(8);
    char *c = malloc(8);
    while (n) {
        n = n - 1;
        a = n % 26;
        b[count++] = a + 'A';
        n /= 26;
    }

    for (int i = count - 1; i >= 0; i--) {
        c[count - 1 - i] = b[i];
    }

    c[count] = '\0';
    return c;
}

void test(int n, char *wanted) {
    char *actual = convertToTitle(n);
    compare(wanted, actual);
}

int main() {
    test(1, "A");
    test(28, "AB");
    test(701, "ZY");
    test(2147483647, "FXSHRXW");
}
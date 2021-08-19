#include <stdbool.h>
#include <stdio.h>

bool isUgly(int n) {
    if (n < 1) {
        return false;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    return (n == 1);
}

char *bool2str(bool a) { return a ? "true" : "false"; }

void test(int n, char wanted) {
    char actual = isUgly(n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %s but actual = %s\n", n,
               bool2str(wanted), bool2str(actual));
    }
}

int main() {
    test(1, true);
    test(14, false);
    test(6, true);
    test(8, true);
    test(2147483647, false);
    test(-2147483648, false);
}
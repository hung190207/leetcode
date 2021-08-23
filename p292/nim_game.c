#include <stdbool.h>
#include <stdio.h>

bool canWinNim(int n) {
    if (n < 4) {
        return true;
    }
    return n % 4;
}

char* bool2str(bool a) { return a ? "true" : "false"; }

void test(int n, char wanted) {
    char actual = canWinNim(n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %s but actual = %s\n", n,
               bool2str(wanted), bool2str(actual));
    }
}

int main() {
    test(4, false);
    test(2147483647, true);
    test(1, true);
    test(2, true);
    test(3, true);
    test(4, false);
    test(5, true);
    test(8, false);
}
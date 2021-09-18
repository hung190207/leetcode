#include <stdbool.h>
#include <stdio.h>

#include "../lib/bool.h"

bool checkPerfectNumber(int n) {
    int sum = 1;
    int a = 3;
    for (int i = 2; i < a; i++) {
        a = n / i;
        if (n % i == 0) {
            if (a == i) {
                sum = sum + i;
            } else {
                sum = sum + i + (n / i);
            }
        }
    }

    if (sum == n && n != 1) {
        return true;
    }

    return false;
}

void test(int n, char wanted) {
    char actual = checkPerfectNumber(n);
    if (actual != wanted) {
        printf("ERROR : n = %d , wanted = %s but actual = %s\n", n,
               bool2str(wanted), bool2str(actual));
    }
}

int main() {
    test(2, false);
    test(28, true);
    test(6, true);
    test(496, true);
    test(8128, true);
}
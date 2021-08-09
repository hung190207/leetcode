#include <stdio.h>

int fib(int n) {
    if (n < 0) {
        return 0;
    }

    if (n <= 1) {
        return n;
    }

    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

void test(int n, int wanted) {
    int actual = fib(n);
    if (actual != wanted) {
        printf("ERROR:n = %d , wanted = %d but actual = %d\n", n, wanted,
               actual);
    }
}

int main() {
    int fib_numbers[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    int n = sizeof(fib_numbers) / sizeof(int);
    for (int i = 0; i < n; i++) {
        int f = fib_numbers[i];
        test(i, f);
    }

    test(30, 832040);
}
#include <stdio.h>

// TODO : Need to know how gcd function working.
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
int findGCD(int* arr, int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (max > arr[i]) {
            max = arr[i];
        }
        if (min < arr[i]) {
            min = arr[i];
        }
    }
    return gcd(max,min);
}

void test(int* arr, int n, int wanted) {
    int actual = findGCD(arr, n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %d but actual = %d\n", n, wanted,
               actual);
    }
}

int main() {
    test((int[]){7, 5, 6, 8, 3}, 5, 1);
    test((int[]){2, 5, 6, 9, 10}, 5, 2);
    test((int[]){3, 3}, 2, 3);
}
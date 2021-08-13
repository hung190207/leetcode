#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* arr, int n, int* return_n) {
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    *return_n = n;
    return arr;
}

void test(int* arr, int n, int* wanted) {
    int return_n = 0;

    int* result = runningSum(arr, n, &return_n);

    if (return_n != n) {
        printf("ERROR: return_n=%d, n=%d\n", return_n, n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (result[i] != wanted[i]) {
            printf("ERROR: result[%d]=%d, wanted[%d]=%d\n", i, result[i], i,
                   wanted[i]);
        }
    }
}

int main() {
    test((int[]){1, 2, 3, 4}, 4, (int[]){1, 3, 6, 10});
    test((int[]){1, 1, 1, 1, 1}, 5, (int[]){1, 2, 3, 4, 5});
    test((int[]){3, 1, 2, 10, 1}, 5, (int[]){3, 4, 6, 16, 17});
}

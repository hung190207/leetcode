#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int c = *(int*)a;
    int d = *(int*)b;

    if (c > d) {
        return 1;
    } else if (c < d) {
        return -1;
    } else {
        return 0;
    }
}

int minMoves(int* arr, int n) {
    int i;
    int a = 0;

    if (n <= 1) {
        return 0;
    }

    qsort(arr, n, sizeof(*arr), compare);

    for (i = 1; i < n; i++) {
        a = a + (arr[i] - arr[0]);
    }

    return a;
}

void test(int* arr, int n, int wanted) {
    int actual = minMoves(arr, n);
    if (actual != wanted) {
        printf("ERROR: wanted = %d but actual = %d\n", wanted, actual);
    }
}

int main() {
    test((int[]){1, 2, 3}, 3, 3);
    test((int[]){1, 1, 1}, 3, 0);
}
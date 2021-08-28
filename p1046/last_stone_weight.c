#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) { return (*(int*)b - *(int*)a); }

// TODO: this is O(n^2 log(n)), can be faster, can be O(n logn).
int lastStoneWeight(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        qsort(arr, n, sizeof(int), compare);
        if (arr[i] >= arr[i + 1]) {
            arr[i + 1] = arr[i] - arr[i + 1];
        }
    }
    return arr[n - 1];
}

void test(int* arr, int n, int wanted) {
    int actual = lastStoneWeight(arr, n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %d but actual = %d\n", n, wanted,
               actual);
    }
}

int main() {
    test((int[]){2, 7, 4, 1, 8, 1}, 6, 1);
    test((int[]){1}, 1, 1);
}
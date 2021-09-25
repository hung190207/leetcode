#include <stdio.h>
#include <stdlib.h>

#include "../lib/bool.h"

// Runtime: 39 ms, faster than 20.60% of C online submissions for Valid Mountain
// Array.

bool validMountainArray(int* arr, int n) {
    int i = 0;
    while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }
    if (i == 0 || i == n - 1) {
        return false;
    }
    while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }
    return i == n - 1;
}

void test(int* arr, int n, char wanted) {
    char actual = validMountainArray(arr, n);
    if (actual != wanted) {
        printf("ERROR : wanted = %s but actual = %s\n", bool2str(wanted),
               bool2str(actual));
    }
}

int main() {
    test((int[]){2, 1}, 2, false);
    test((int[]){3, 5, 5}, 3, false);
    test((int[]){0, 3, 2, 1}, 4, true);
}
#include <stdio.h>

//Runtime: 12 ms, faster than 89.67% of C online submissions for Move Zeroes.

void moveZeroes(int* arr, int n) {
    int i = 0;
    int j = 0;
    while (j < n) {
        if (arr[j] != 0) {
            arr[i] = arr[j];
            i++;
        }
        j++;
    }

    while (i < n) {
        arr[i] = 0;
        i++;
    }
}
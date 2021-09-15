#include <stdio.h>
#include <stdlib.h>

#include "../lib/array.h"

// TODO : Solve it without using internet.
// Runtime: 4 ms, faster than 52.27% of C online submissions for Plus One.

char compareArray(int a[], int b[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] != b[i]) return 1;
    }
    return 0;
}

int* plusOne(int* digits, int size, int* return_size) {
    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            digits[i]++;
            break;

        } else {
            digits[i] = 0;
        }
    }

    if (digits[0] == 0) {
        int* new_array = malloc(sizeof(int) * (size + 1));
        new_array[0] = 1;
        int j = 0;
        for (int i = 1; i < size + 1; i++) {
            new_array[i] = digits[j];
            j++;
        }
        *return_size = size + 1;
        return new_array;
    }
    *return_size = size;
    return digits;
}

void test(int* digits, int size, int* return_size, int* wanted) {
    int* actual = plusOne(digits, size, return_size);
    compare_array(wanted ,actual,size);
}

int main() {
    test((int[]){1, 2, 3, 4}, 4, (int[]){1, 2, 3, 5}, (int[]){1, 2, 3, 5});
}
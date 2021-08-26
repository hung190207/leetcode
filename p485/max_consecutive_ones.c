#include <stdio.h>

//Runtime: 36 ms, faster than 84.96% of C online submissions for Max Consecutive Ones.

int findMaxConsecutiveOnes(int* arr, int n) {
    int count = 0;
    int count_2 = 0;
    for (int i = 0; i < n ; i++) {
        if (arr[i] == 1) {
            count++;
        } else {
            count = 0;
        }
        if (count_2 < count) {
            count_2 = count;
        }
    }
    return count_2;
}

void test(int* arr, int n, int wanted) {
    int actual = findMaxConsecutiveOnes(arr, n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %d but actual = %d\n", n, wanted,
               actual);
    }
}

int main() {
    test((int[]){1, 1, 0, 1, 1, 1}, 6, 3);
    test((int[]){1, 0, 1, 1, 0, 1}, 6, 2);
    test((int[]){1, 1, 1, 1, 1}, 5, 5);
    test((int[]){0},1,0);
}
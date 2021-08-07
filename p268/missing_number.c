#include <stdio.h>

//Runtime: 16 ms, faster than 82.87% of C online submissions for Missing Number.

int missingNumber(int *arr, int n)
{
    int sum = (n * (n + 1)) / 2;
    int sum_number = 0;
    for (int i = 0; i < n; i++){
        sum_number += arr[i];
    }
    return (sum - sum_number);
}

void test(int *arr, int n, int wanted)
{
    int actual = missingNumber(arr, n);
    if (actual != wanted){
        printf("ERROR: n = %d,wanted = %d but actual = %d\n", n, wanted, actual);
    }
}

int main()
{
    test((int[]){3, 0, 1}, 3, 2);
    test((int[]){0, 1}, 2, 2);
    test((int[]){9, 6, 4, 2, 3, 5, 7, 0, 1}, 9, 8);
    test((int[]){0}, 1, 1);
}
#include <stdio.h>
#include <limits.h>

// https://leetcode.com/problems/maximum-subarray
// Memory Usage: 6.6 MB, less than 29.86% of C 
// online submissions for Maximum Subarray.
//
// TODO (hung): optimize, lam cho no nhanh hon, 100%

int maxSubArray(int *arr, int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

void show(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test(int *arr, int size, int wanted)
{
    int actual = maxSubArray(arr, size);
    if (actual != wanted)
    {
        printf("ERROR: wanted=%d, but actual=%d\n", wanted, actual);
        show(arr, size);
    }
}

int main()
{

    test(
        (int[]){3}, // arr
        1,          // size
        3           // wanted
    );

    test(
        (int[]){-3, 6}, // arr
        2,              // size
        6               // wanted
    );

    test(
        (int[]){-3, -6}, // arr
        2,               // size
        -3               // wanted
    );

    test(
        (int[]){-2, 1, -3, 4, -1, 2, 1, -5, 4}, // arr
        9,                                      // size
        6                                       // wanted
    );

    test(
        (int[]){-5, 4, -1, 7, 8}, // arr
        5,                        // size
        18                        // wanted
    );
    return 0;
}

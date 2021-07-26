#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(int arr[], int n)
{
    if (n == 0) {
        return 0;
    }

    int j = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[j - 1])
        {
            arr[j++] = arr[i];
        }
    }
    /*
    for (i = 0; i < n - 1; i++)
    {
        //                                           i
        // arr:   1,    2,   3,    4, 5, 6,      4, 5, 5, 6
        //                                  j <- where to put the next unique number
        if (arr[i] != arr[i + 1])
        {
            temp[j] = arr[i];
            j++;
        }
    }
    temp[j] = arr[n - 1];
    j++;

    for (i = 0; i < j; i++)
    {
        arr[i] = temp[i];
    }
*/
    return j;
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
    int actual = removeDuplicates(arr, size);
    if (actual != wanted)
    {
        printf("ERROR: wanted=%d, but actual=%d\n", wanted, actual);
        show(arr, actual);
        return;
    }

    for (int i = 0; i < wanted - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            printf("ERROR: Array is not strictly increasing at index=%d\n", i);
            show(arr, wanted);
            return;
        }
    }

    show(arr, wanted);
}

int main()
{
    test((int[]){1, 2, 2, 3}, 4, 3);
    test((int[]){0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 10, 5);
    return 0;
}
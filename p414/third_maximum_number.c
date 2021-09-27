#include <limits.h>
#include <stdio.h>

int thirdMax(int* arr, int n) {
    int third = 0;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    for (int i = 0; i < n; i++) {
        max1 = max1 > arr[i] ? max1 : arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != max1) max2 = max2 > arr[i] ? max2 : arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != max1 && arr[i] != max2) {
            max3 = max3 > arr[i] ? max3 : arr[i];
            third = 1;
        }
    }
    if (third == 1) return max3;
    return max1;
}
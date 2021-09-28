#include <stdio.h>
#include <math.h>

int smallestRangeI(int* arr, int n, int k) {
    int max;
    int min;
    int range;
    int i;
    if (n < 2) {
        return 0;
    }
    max = arr[0];
    min = arr[0];
    for (i = 0; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
        else if (min > arr[i])
            min = arr[i];
        range = abs(max - min) - 2 * k;
        // About (abs) func : https://www.tutorialspoint.com/c_standard_library/c_function_abs.htm
    }
    if (range < 0) {
        range = 0;  
    }
    return range;
}

void test(int* arr, int n,int k ,int wanted){
    int actual = smallestRangeI(arr,n,k);
    if(actual != wanted){
        printf("ERROR: k = %d , wanted = %d but actual = %d\n",k,wanted,actual);
    }
}

int main(){
    test((int[]){1},1,0,0);
    test((int[]){0,10},2,2,6);
    test((int[]){1,3,6},3,3,0);
}
#include <stdio.h>

int removeElement(int* arr, int n, int val) {
    int a = n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != val) {
            arr[count] = arr[i];
            count++;
        } else {
            a--;
        }
    }
    return a;
}

void test(int* arr, int n, int val, int wanted) {
    int actual = removeElement(arr, n, val);
    if (actual != wanted) {
    // I don't print arr after remove element in arr[n] like on leetcode. 
        printf("ERROR: n = %d , value = %d , wanted = %d but actual = %d\n", n,
               val, wanted, actual);
    }
}

int main(){
    test((int[]){1,1,1,1},4,1,0);
    test((int[]){0,1,2,2,3,0,4,2},8,2,5);
    test((int[]){3,2,2,3},4,3,2);
    test((int[]){1,2,3,4,5,6,5,4,6},9,5,7);
}
#include <stdio.h>

int singleNumber(int* arr, int n) {
    int a = 0;
    for (int i = 0; i < n; i++){
        a ^= arr[i];
    }
    return a;
}

void test(int* arr, int n , int wanted){
    int actual = singleNumber(arr,n);
    if(actual != wanted){
        printf("ERROR: n = %d , wanted = %d but actual = %d\n",n,wanted,actual);
    }
}

int main(){
    test((int[]){2,2,1},3,1);
}
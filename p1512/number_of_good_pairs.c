#include <stdio.h>
#include <stdlib.h>

int numIdenticalPairs(int* arr, int n){
    int p = 0;
    for(int i = 0 ; i < n-1 ; i ++){
        for(int j = i+1 ; j < n ; j ++){
            if(arr[i] == arr[j] && i < j ){
                p++;
            }
        }
    }
    return p;
}

void test(int* arr, int n , int wanted){
    int actual = numIdenticalPairs(arr,n);
    if(actual != wanted){
        printf("ERROR: n = %d , wanted = %d but actual = %d\n",n,wanted,actual);
    }
}

int main(){
    test((int[]){1,2,3,1,1,3},6,4);
    test((int[]){1,1,1,1},4,6);
    test((int[]){1,2,3},3,0);
}
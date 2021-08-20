#include <stdio.h>

int trailingZeroes(int n){
    int i = 0;
    while ( n >= 5){
        i += n /5;
        n /= 5;
    }
    return i;
}

void test(int n , int wanted){
    int actual = trailingZeroes(n);
    if(actual != wanted){
        printf("ERROR: n = %d , wanted = %d but actual = %d\n",n,wanted,actual);
    }
}

int main(){
    test(5,1);
    test(10000,2499);
}
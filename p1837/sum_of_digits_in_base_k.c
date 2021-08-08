#include <stdio.h>

//Runtime: 0 ms, faster than 100.00% of C online submissions for Sum of Digits in Base K.

int sumBase(int n, int k) {
    int sum = 0;
    while (n != 0) {
        int r = n % k;
        sum += r;
        n /= k;
    }

    return sum;
}

void test(int n , int k , int wanted){
    int actual = sumBase(n,k);
    if(actual != wanted){
        printf("ERROR: n = %d ,k = %d, wanted = %d but actual = %d\n",n,k,wanted,actual);
    }
}

int main(){
    test(34,6,9);
    test(10,10,1);
    test(100,2,3);
    test(34,4,4);
}


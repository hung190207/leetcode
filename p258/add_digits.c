#include <stdio.h>

// Runtime: 4 ms, faster than 51.14% of C online submissions for Add Digits.

int addDigits(int n){    
   if(n<=9)
      return n;
   int sum = n%9;
   if(sum)
      return sum;
   return 9;
}

void test(int n , int wanted ) {
    int actual = addDigits(n);
    if(actual != wanted){
        printf("ERROR: n = %d , wanted = %d but actual = %d\n",n,wanted,actual);
    }
}

int main(){
    test(38,2);
    test(0,0);
    test(2147483647,1);
}
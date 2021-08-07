#include <stdio.h>

int arr[31] = {0,1};
int fib(int n)
{
    for(int i=2;i<=n;i++)
    {
        arr[i] = arr[i-1] + arr[i-2] ;
    }
    
    return arr[n];
}

void test(int n , int wanted){
    int actual = fib(n);
    if(actual != wanted){
        printf("ERROR:n = %d , wanted = %d but actual = %d\n",n,wanted,actual);
    }
}

int main(){
    test(2,1);
    test(3,2);
    test(4,3);
    test(30,832040);
}
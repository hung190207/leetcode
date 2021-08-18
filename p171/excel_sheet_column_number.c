#include <stdio.h>
#include <string.h>

int titleToNumber(char* c){
    int a = strlen(c);
    int val = 0;
    for ( int i = 0 ; i < a ; i++ ){
        val = val * 26 + (c[i]-'A' + 1);
    }
    return val;
}

void test(char* c , int wanted){
    int actual = titleToNumber(c);
    if(actual != wanted){
        printf("ERROR: columnTitle = %s , wanted = %d but actual %d\n",c,wanted,actual);
    }
}

int main(){
    test("A",1);
    test("AB",28);
    test("ZY",701);
    test("FXSHRXW",2147483647);
}
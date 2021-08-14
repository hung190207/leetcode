#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    int y;
    int t = x;
    long long sum = 0;
    while (t > 0) {
        y = t % 10;
        t = t / 10;
        sum = sum * 10 + y;
    }
    if (sum == x) return true;
    return false;
}

char* bool2str(bool b) { return b ? "true" : "false"; }

void test(int x, bool wanted) {
    bool actual = isPalindrome(x);
    if (actual != wanted) {
        printf("ERROR: number = %d , wanted = %s but actual = %s\n", x,
               bool2str(wanted), bool2str(actual));
    }
}

int main(){
    test(121,true);
    test(-121,false);
    test(10,false);
    test(-101,false);
}
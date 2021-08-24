#include <stdbool.h>
#include <stdio.h>

bool divisorGame(int n) {
    // TODO why it work?
    return n % 2 == 0;
}

char* bool2str(bool a) { return a ? "true" : "false"; }

void test(int n, char wanted) {
    char actual = divisorGame(n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %s but actual = %s\n", n,
               bool2str(wanted), bool2str(actual));
    }
}

int main(){
    test(2,true);
    test(12,true);
    test(3,false);
}
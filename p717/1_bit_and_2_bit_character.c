#include <stdbool.h>
#include <stdio.h>

bool isOneBitCharacter(int* arr, int n) {
    int b = 0;
    if (arr[n - 1] == 1) {
        return false;
    }
    for (int i = 0; i < n; i += b) {
        b = arr[i] + 1;
    }
    return b == true;
}

char* bool2str(bool a) { return a ? "true" : "false"; }

void test(int* arr, int n, char wanted) {
    char actual = isOneBitCharacter(arr, n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %s but actual = %s\n", n,
               bool2str(wanted), bool2str(actual));
    }
}

int main(){
    test((int[]){1,0,0},3,true);
    test((int[]){1,1,1,0},4,false);
}
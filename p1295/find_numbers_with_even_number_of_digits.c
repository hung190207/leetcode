#include <stdio.h>

int findNumbers(int* arr, int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        while (arr[i] > 0) {
            arr[i] /= 10;
            count++;
        }
        if (count >= 2 && count % 2 == 0) {
            x++;
        }
    }
    return x;
}

void test(int* arr, int n, int wanted) {
    int actual = findNumbers(arr, n);
    if (actual != wanted) {
        printf("ERROR: n = %d , wanted = %d but actual = %d\n", n, wanted,
               actual);
    }
}

int main(){
    test((int[]){12,345,2,6,7896},5,2);
    test((int[]){555,901,482,1771},4,1);
}
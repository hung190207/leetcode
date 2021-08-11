#include <stdio.h>

// a = the best day to sell
// b = the best day to buy

//                  a
// prices : 7,1,5,3,6,4
//            b

// j = profit after buy and sell .
// => j = a - b = 6 - 1 = 5

// Runtime: 108 ms, faster than 92.44% of C online submissions for Best Time to Buy and Sell Stock.
int maxProfit(int* p, int size) {
    int a = p[0];
    int b = p[0];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (b > p[i]) {
            a = b = p[i];
        }
        if (a < p[i]) {
            a = p[i];
        }
        if(a - b > j){
            j = a - b;
        }
    }
    return j;
}

void test(int* p, int size, int wanted) {
    int actual = maxProfit(p, size);
    if (actual != wanted) {
        printf("ERROR: profit = %d , wanted = %d but actual = %d\n", size,
               wanted, actual);
    }
}

int main() {
    test((int[]){7, 1, 5, 3, 6, 4}, 6, 5);
    test((int[]){7, 6, 4, 3, 1}, 5, 0);
    test((int[]){1,2},2,0);
}
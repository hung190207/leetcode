#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPowerOfThree(int n) {
  // 3486784401u is 3^20 and the largest power of 3 that can be represented in
  // 32bit unsigned

  // unsigned int
  // n == 3^k
  // x = 3^(k+i) > n; x % n == 0
  return n != 0 && 3486784401u % n == 0;

  /*
    if (n == 0) return 0;
    while (n != 1) {
      if (n % 3 != 0) {
        return 0;
      }
      n = n / 3;
    }
    return 1;
    */
}

void test(int n, bool wanted) {
  bool actual = isPowerOfThree(n);
  if (actual != wanted) {
    printf("ERROR: num=%d, wanted=%d but actual=%d \n", n, wanted, actual);
  }
}

int main() {
  test(1, true);
  test(27, true);
  test(0, false);
  test(9, true);
  test(45, false);
  test(5, false);
  test(-2147483648, false);
  test(2147483647, false);
}
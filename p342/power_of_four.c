#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
  return n > 0 && (!(n & n - 1)) && (n & 0x55555555);
}

void test(int n, bool wanted) {
  bool actual = isPowerOfFour(n);
  if (actual != wanted) {
    printf("ERROR: num=%d, wanted=%d but actual=%d \n", n, wanted, actual);
  }
}

int main() {
  test(1, true);
  test(16,true);
  test(5, false);
  test(-2147483648, false);
  test(2147483647, false);
}
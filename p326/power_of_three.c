#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool power_of_three(int n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 3 != 0) {
      return 0;
    }
    n = n / 3;
  }
  return 1;
}

bool isPowerOfThree(int n) { return power_of_three((int)n); }

void test(int n, bool wanted) {
  bool actual = power_of_three(n);
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
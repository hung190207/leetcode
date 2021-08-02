#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// bitwise solution: O(1)
bool isPowerOfTwo(int n) { return (n > 0) && ((n & (n - 1)) == 0); }

/*
o(log_2(n)): logarithm base  2of
*/
/*
bool isPowerOfTwo(int n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 2 != 0) {
      return 0;
    }
    n = n / 2;
  }
  return 1;
}
*/

char* bool2str(bool b) { return b ? "true" : "false"; }

void test(int n, bool wanted) {
  bool actual = isPowerOfTwo(n);
  if (actual != wanted) {
    printf("ERROR: num=%d, wanted=%s but actual=%s \n", n, bool2str(wanted),
           bool2str(actual));
  }
}

int main() {
  test(1, true);
  test(16, true);
  test(3, false);
  test(-16, false);

  test(4, true);
  test(5, false);
  test(-2147483648, false);
  test(2147483647, false);
}
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>



// TODO (hung): try to understand this, and solve this problem again
double pow(double x, long n) {
  if (x == 1) {
    return 1;
  }
  if (x == -1) {
    if (n % 2 == 1) {
      return -1;
    }
    return 1;
  }
  if (n < 0) {
    return 1.0 / pow(x, -n);
  }

  // r=1,         c=x,     n=43
  // r=x,         c=x,     n=42
  // r=x,         c=x^2,   n=21
  // r=r*c=x^3,   c=x^2,   n=20
  // r=x^3,       c=x^4,   n=10
  // r=x^3,       c=x^8,   n=5
  // r=x^11,      c=x^8,   n=4
  // r=x^11,      c=x^16,  n=2
  // r=x^11,      c=x^32,  n=1
  // r=x^43,      c=x^32,  n=0
  double r = 1;
  double c = x;
  while (n > 0) {
    if (n % 2 == 0) {
      n /= 2;
      c *= c;
    } else {
      --n;
      r *= c;
    }
  }
  return r;
}

double myPow(double x, int n) {
  return pow(x, (long)n);
}

void test(double x, int n, double wanted) {
  double actual = myPow(x, n);
  if (actual != wanted) {
    printf("ERROR: x=%lf, n=%d, wanted=%lf but actual=%lf\n", x, n, wanted,
           actual);
  }
}

int main() {
  test(1, INT_MAX, 1);
  // test(0.9, INT_MAX, 1);
  test(2, 3, 8);
  test(1.5, 4, 5.0625);
  test(-1, 4, 1);
  test(-1, 3, -1);
  test(2, -2, 0.25);
  // test(2.1000, 3, 9.261000);
  test(2, 10, 1024);
}
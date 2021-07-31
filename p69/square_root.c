#include <stdio.h>

int mySqrt(int x) {
  if (x == 1) {
    return x;
  }

  double temp, sqrt;
  sqrt = x / 2;
  temp = 0;
  while (sqrt != temp) {
    temp = sqrt;
    sqrt = (x / temp + temp) / 2;
  }

  return sqrt;
}

// Runtime: 16 ms, faster than 33.38%
// of C online submissions for Sqrt(x).

/*
int mySqrt(int x) // 10
{
    if (x <= 1)
    {
        return x; // x is 0, 1, ...
    }

    // from here, x is 2, 3, ...,
    // so sqrt(x) <= x/2
    for (unsigned int sqrt = 0; sqrt <= x / 2 + 1; sqrt++)
    {
        unsigned int temp = sqrt * sqrt;
        if (temp == x)
        {
            return sqrt;
        }

        if (temp > x)
        {
            return sqrt - 1;
        }
    }

    return 0;
}
*/

void test(int x, int wanted) {
  int actual = mySqrt(x);
  if (actual != wanted) {
    printf("ERROR:interger=%d,wanted=%d but actual=%d\n", x, wanted, actual);
  }
}

int main() {
  test(2147395599, 46339);
  test(2147483647, 46340);
  test(144, 12);
  test(36, 6);
  test(3136, 56);
  test(1, 1);
  test(2, 1);
  test(10, 3);
}
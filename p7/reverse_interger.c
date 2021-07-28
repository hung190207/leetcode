#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
    long int rx = 0;
    while (x != 0)
    {
        int d = x % 10;
        rx = rx * 10 + d;
        x /= 10;
    }
    if(rx > 2147483648)//2^31
    {
        return 0;
    }
    if(rx < -2147483648)// - 2^31
    {
        return 0;
    }
    return rx;
}

void test(int x, int wanted)
{
    int actual = reverse(x);
    if (actual != wanted)
    {
        printf("ERROR: x=%d, wanted=%d but actual=%d\n", x, wanted, actual);
    }
}

int main()
{
    test(2000000003, 0); // the reversed number overflows.
    test(-2000000003, 0); // the reversed number overflows.
    test(-1000000, -1);
    test(-10, -1);
    test(1, 1);
    test(0, 0);
    test(120, 21);
    test(-1, -1);
    test(-123, -321);
    test(123, 321);
}
#include <stdio.h>

//Runtime: 0 ms, faster than 100.00% of C online submissions for Roman to Integer.

int romanToInt(char* s) {
    int i = 0;
    int result = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case 'I':
                if (s[i + 1] == 'X' || 'V' == s[i + 1]) {
                    result -= 1;
                } else {
                    result += 1;
                }
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if (s[i + 1] == 'L' || 'C' == s[i + 1]) {
                    result -= 10;
                } else {
                    result += 10;
                }
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if (s[i + 1] == 'D' || 'M' == s[i + 1]) {
                    result -= 100;
                } else {
                    result += 100;
                }
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
        }
        i++;
    }
    return result;
}

void test(char* s, int wanted) {
    int actual = romanToInt(s);
    if (actual != wanted) {
        printf("ERROR:str = %s , wanted = %d but actual = %d\n", s, wanted,
               actual);
    }
}

int main() {
    test("I", 1);
    test("III", 3);
    test("IV", 4);
    test("IX", 9);
    test("LVIII", 58);
    test("MCMXCIV", 1994);
    test("MCMXCIX",1999);
    test("MMMCMXCIX", 3999);
}
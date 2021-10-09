#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../lib/bool.h"

// Runtime: 4 ms, faster than 72.08% of C online submissions for Valid
// Palindrome.

bool isPalindrome(char* s) {
    int l = 0;
    int r = strlen(s) - 1;

    while (l < r) {
        // About isalnum func : Vietnamese:
        //                      https://vietjack.com/thu-vien-c/ham-isalnum-trong-c.jsp
        //                      English :
        //                      https://www.programiz.com/c-programming/library-function/ctype.h/isalnum
        if (!isalnum(s[l])) {
            l++;
        }

        if (!isalnum(s[r])) {
            r--;
        }

        if (isalnum(s[l]) && isalnum(s[r])) {
            if ((s[l] | ' ') != (s[r] | ' ')) { // You can change (space) to 32 in Ascii table.
                return false;
            }
            l++;
            r--;
        }
    }

    return true;
}

void test(char* s, char wanted) {
    char actual = isPalindrome(s);
    if (actual != wanted) {
        printf("ERROR : str = %s , wanted = %s but actual = %s\n", s,
               bool2str(wanted), bool2str(actual));
    }
}

int main() {
    test("A man, a plan, a canal: Panama", true);
    test("race a car", false);
}
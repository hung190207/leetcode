#include <stdio.h>

#include "../lib/list.h"

//Runtime: 4 ms, faster than 10.65% of C online submissions for Convert Binary Number in a Linked List to Integer.
//Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/

int getDecimalValue(struct ListNode* head) {
    int a = head->val;
    // v{head}
    // v
    // 1 -> 0 -> 1
    //      ^
    //      ^ {head->val != NULL}
    //
    // result = 5
    while (head->next != NULL) {
        a = (a * 2) + head->next->val;
        head = head->next;
    }
    return a;
}

void test(struct ListNode* head, int wanted) {
    int actual = getDecimalValue(head);
    printf("\nList:\n");
    print_list(head);
    if (actual != wanted) {
        printf("ERROR: wanted = %d but actual = %d\n", wanted, actual);
    } else {
        printf("Result = %d \n", wanted);
    }
}

int main() {
    test(makeList(3, 1, 0, 1), 5);
    test(makeList(4, 1, 1, 0, 1), 13);
    test(makeList(4,0,1,0,1),5); // 4 bit binary numbers case
}
#include <stdio.h>

#include "../lib/list.h"

// Runtime: 11 ms, faster than 81.48% of C online submissions for Add Two
// Numbers.
// TODO : Solve it without using help by internet.

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node = temp;
    int rem = 0;
    temp->val = 0;
    node->next = NULL;
    while (l1 != NULL || l2 != NULL || rem != 0) {
        int sum = 0;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += rem;
        rem = sum / 10;
        node->val = sum % 10;
        if (l1 != NULL || l2 != NULL || rem != 0) {
            node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            node = node->next;
            node->next = NULL;
        }
    }
    return temp;
}

void test(struct ListNode* l1, struct ListNode* l2, struct ListNode* wanted) {
    struct ListNode* actual = addTwoNumbers(l1, l2);
    printf("\n");
    printf("       List 1: ");
    print_list(l1);
    printf("       List 2: ");
    print_list(l2);
    printf("Wanted List  : ");
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(3, 2, 4, 3),  //
         makeList(3, 5, 6, 4),  //
         makeList(3, 7, 0, 8));
}
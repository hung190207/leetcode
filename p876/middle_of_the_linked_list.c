#include <stdio.h>

#include "../lib/list.h"

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* a = head;
    struct ListNode* b = head;
    // sample test:

    // a
    // 1 -> 2 -> 3 -> 4 -> 5
    // b

    // after while:

    //           a
    //           V
    // 1 -> 2 -> 3 -> 4 -> 5
    //                     ^
    //                     b

    // The list after while loop is :

    // a = 3 -> 4 -> 5
    while (a != NULL && b != NULL && a->next != NULL && b->next != NULL) {
        a = a->next;
        b = b->next->next;
    }
    return a;
}

void test(struct ListNode* head, struct ListNode* wanted) {
    struct ListNode* actual = middleNode(head);
    printf("List:\n");
    print_list(head);
    printf("Middle Node : \n");
    print_list(actual);
    printf("Wanted List: \n");
    print_list(wanted);
    assert_list_equal(actual, wanted);
}

int main() { test(makeList(5, /*size*/ 1, 2, 3, 4, 5), makeList(3, 3, 4, 5)); }
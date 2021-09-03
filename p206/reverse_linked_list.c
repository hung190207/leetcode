#include <stdio.h>
#include <stdlib.h>

#include "../lib/list.h"

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newHead = NULL;
    struct ListNode* tmpNode;
    while (head != NULL) {
        tmpNode = head->next;
        head->next = newHead;
        newHead = head;
        head = tmpNode;
    }
    return newHead;
}

void test(struct ListNode* head, struct ListNode* wanted) {
    struct ListNode* actual = reverseList(head);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(5, /*size*/ 1, 2, 3, 4, 5),
         makeList(5, /*size*/ 5, 4, 3, 2, 1));

    test(makeList(1, /**/ 1), makeList(1, /**/ 1));

    test(NULL, NULL);
}
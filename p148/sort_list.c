#include <stdio.h>

#include "../lib/list.h"

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    struct ListNode* fast;
    struct ListNode* slow;
    struct ListNode* node;
    fast = slow = head;
    while (fast && fast->next) {
        node = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    node->next = NULL;
    return merge_list(sortList(head), sortList(slow));
}
void test(struct ListNode* head, struct ListNode* wanted) {
    struct ListNode* actual = sortList(head);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(4, 3, 2, 1, 4),  //
         makeList(4, 1, 2, 3, 4));
}
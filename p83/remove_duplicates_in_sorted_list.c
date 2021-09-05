#include <stdio.h>

#include "../lib/list.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* prev = head;
    struct ListNode* node = head->next;
    while (node) {
        if (prev->val == node->val) {
            struct ListNode* temp = node->next;
            prev->next = temp;
            node = temp;
        }else{
            prev = node;
            node = node->next;
        }
    }
    return head;
}

void test(struct ListNode* head, struct ListNode* wanted) {
    struct ListNode* actual = deleteDuplicates(head);
    print_list(head);
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main() { test(makeList(3, 1, 1, 2), makeList(2, 1, 2)); }
#include <stdio.h>

#include "../lib/list.h"

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* node = head;
    struct ListNode* temp;

    while (node && node->val == val) {
        head = node->next;
        free(node);
        node = head;
    }

    while (node && node->next) {
        if (node->next->val == val) {
            temp = node->next;
            node->next = temp->next;
            free(temp);
        } else {
            node = node->next;
        }
    }
    return head;
}

void test(struct ListNode* head, int val, struct ListNode* wanted) {
    struct ListNode* actual = removeElements(head, val);
    printf("\n");
    printf("       List: ");
    print_list(head);
    printf("Wanted List: ");
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(5, 1, 2, 3, 4, 5),  //
         4,                           //
         makeList(4, 1, 2, 3, 5));
}
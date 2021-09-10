#include <stdio.h>

#include "../lib/list.h"

// Runtime: 13 ms, faster than 7.63% of C online submissions for Odd Even Linked List.
// https://leetcode.com/problems/odd-even-linked-list/submissions/

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* node = head;
    struct ListNode* another_head = malloc(sizeof(struct ListNode));
    another_head->next = NULL;
    struct ListNode* node_2 = another_head;
    while (node && node->next) {
        struct ListNode* temp = node->next;
        node->next = temp->next;
        temp->next = NULL;
        node_2->next = temp;
        node_2 = temp;
        if (node->next != NULL) {
            node = node->next;
        }
    }
    node->next = another_head->next;
    return head;
}

void test(struct ListNode* head, struct ListNode* wanted) {
    struct ListNode* actual = oddEvenList(head);
    printf("\n");
    printf("       List: ");
    print_list(head);
    printf("Wanted List: ");
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(5, 1, 2, 3, 4, 5),  //
         makeList(5, 1, 3, 5, 2, 4));
}
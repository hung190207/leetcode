#include <stdio.h>

#include "../lib/list.h"

void deleteNode(struct ListNode* head) {
    struct ListNode* temp = head->next;
    head->val = temp->val;
    head->next = temp->next;
    free(temp);
}

void test(struct ListNode* input, int toBeDeleted, struct ListNode* wanted) {
    printf("Input: \n");
    print_list(input);

    struct ListNode* nodeToBeDeleted = search_list(input, toBeDeleted);
    printf("Node to be delete: \n");
    print_list(nodeToBeDeleted);

    deleteNode(nodeToBeDeleted);
    printf("After delete:\n");
    print_list(nodeToBeDeleted);

    printf("The list after delete:\n");
    print_list(input);

    // at this point, input should not contains any node with value is
    // toBeDeleted
    assert_list_equal(wanted, input);
}

int main() {
    test(makeList(5, /**/ 4, 5, 1, 9, 0),  // input list
         5,                                // element to be deleted
         makeList(4, /**/ 4, 1, 9, 0)      // wanted list
    );
}
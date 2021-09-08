#include <stdio.h>

#include "../lib/list.h"

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode prev = {0, head};
    struct ListNode* node = &prev;
    struct ListNode* node_2;
    struct ListNode* temp;
    right -= left;
    while (--left > 0) {
        node = node->next;
    }
    node_2 = node->next;
    while (right-- > 0 && node_2->next) {
        temp = node_2->next->next;
        node_2->next->next = node->next;
        node->next = node_2->next;
        node_2->next = temp;
    }
    // This is how is the algorithm run:
    //
    // prev
    // v
    // 1 -> 2 -> 3 -> 4 -> 5
    // ^
    // node

    // right = right - left
    // => right = 2

    // in while :
    // prev
    //  v
    //  1 -> 2 -> 3 -> 4 -> 5
    //       ^
    //      node
    //      node_2

    // in while_2 :
    //               temp
    //                v
    // 1 -> 2 -> 3 -> 4 -> 5
    //      ^
    //     node
    //    node_2

    // node_2->next->next = node->next
    // => 1 -> 2 -> 4 -> 3 -> 5

    // node->next = node_2->next
    // => 1 -> 4 -> 2 -> 3 -> 5

    // node_2->next = temp
    // => 1 -> 4 -> 3 -> 2 -> 5
    return prev.next;
}

void test(struct ListNode* head, int left, int right, struct ListNode* wanted) {
    struct ListNode* actual = reverseBetween(head, left, right);
    printf("\nList:");
    print_list(head);
    printf("\nWanted List:");
    print_list(wanted);
    printf("\n");
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(5, 1, 2, 3, 4, 5), 2, 4,  //
         makeList(5, 1, 4, 3, 2, 5));
    test(makeList(6, 2, 3, 4, 5, 6, 7), 3, 6,  //
         makeList(6, 2, 3, 7, 6, 5, 4));
}
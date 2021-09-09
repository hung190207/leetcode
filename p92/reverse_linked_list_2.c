#include <stdio.h>

#include "../lib/list.h"

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode prev = {0, head};
    struct ListNode* start = &prev;

    right -= left;
    while (--left > 0) {
        start = start->next;
    }

    struct ListNode* end = start->next;
    while (right-- > 0 && end->next) {
        struct ListNode* temp = end->next->next;
        end->next->next = start->next;
        start->next = end->next;
        end->next = temp;
    }

    // This is how is the algorithm run:
    //
    // prev
    // v
    // 1 -> 2 -> 3 -> 4 -> 5
    // ^
    // start

    // right = right - left
    // => right = 2

    // in while :
    // prev
    //  v
    //  1 -> 2 -> 3 -> 4 -> 5
    //       ^
    //      start
    //      end

    // in while_2 :
    //               temp
    //                v
    // 1 -> 2 -> 3 -> 4 -> 5
    //      ^
    //     start
    //    end

    // end->next->next = start->next
    // => 1 -> 2 -> 4 -> 3 -> 5

    // start->next = end->next
    // => 1 -> 4 -> 2 -> 3 -> 5

    // end->next = temp
    // => 1 -> 4 -> 3 -> 2 -> 5
    return prev.next;
}

void test(struct ListNode* head, int left, int right, struct ListNode* wanted) {
    struct ListNode* actual = reverseBetween(head, left, right);
    printf("\n");
    printf("       List: ");
    print_list(head);
    printf("Wanted List: ");
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(5, 1, 2, 3, 4, 5), 2, 4,  //
         makeList(5, 1, 4, 3, 2, 5));

    test(makeList(6, 2, 3, 4, 5, 6, 7), 3, 6,  //
         makeList(6, 2, 3, 7, 6, 5, 4));

    test(makeList(6, 2, 3, 4, 5, 6, 7), 0, 6,  //
         makeList(6, 7, 6, 5, 4, 3, 2));

    test(makeList(6, 2, 3, 4, 5, 6, 7), 1, 1,  //
         makeList(6, 2, 3, 4, 5, 6, 7));
}
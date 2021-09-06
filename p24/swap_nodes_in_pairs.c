#include <stdio.h>

#include "../lib/list.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* runner = head->next;
    struct ListNode* swap = swapPairs(runner->next);
    // printf("Head before use algorithm:\n");
    // print_list(head);
    // printf("\n");
    runner->next = head;
    head->next = swap;
    swap = runner;
    // print_list(runner);
    // printf("Head after use algorithm:\n");
    // print_list(head);
    // printf("\n");
    return swap;
}

void test(struct ListNode* head, struct ListNode* wanted) {
    struct ListNode* actual = swapPairs(head);
    printf("List : \n");
    print_list(head);
    printf("\n");
    printf("Wanted List :\n");
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(4, 1, 2, 3, 4),  //
         makeList(4, 2, 1, 4, 3));
}
#include <stdio.h>

#include "../lib/list.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}

void test(struct ListNode* l1, struct ListNode* l2, struct ListNode* wanted) {
    struct ListNode* actual = mergeTwoLists(l1, l2);
    printf("L1 List: \n");
    print_list(l1);
    printf("L2 List: \n");
    print_list(l2);
    printf("=> Wanted List = ");
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main() {
    test(makeList(3, 1, 2, 3), makeList(2, 4, 5), makeList(5, 1, 2, 3, 4, 5));
    test(NULL, NULL, NULL);
    test(makeList(6, 1, 2, 3, 4, 5, 6), makeList(4, 2, 3, 4, 5),
         makeList(10, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6));
}
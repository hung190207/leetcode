#include <stdio.h>

#include "../lib/list.h"

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    k -= 1;
    while (k && fast != NULL) {
        fast = fast->next;
        k -= 1;
    }
    struct ListNode* node = fast;
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    int temp = node->val;
    node->val = slow->val;
    slow->val = temp;
    return head;
}

void test(struct ListNode* head, int k, struct ListNode* wanted) {
    struct ListNode* actual = swapNodes(head,k);
    printf("\n");
    printf("       List: ");
    print_list(head);
    printf("Wanted List: ");
    print_list(wanted);
    assert_list_equal(wanted, actual);
}

int main(){
    test(makeList(5,1,2,3,4,5),2,//
    makeList(5,1,4,3,2,5));
}

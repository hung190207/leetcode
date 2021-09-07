#include <stdio.h>

#include "../lib/list.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    int i = 0;
    struct ListNode *temp = malloc(sizeof(struct ListNode)), *y = head;
    struct ListNode* node = temp;

    while (y && y->next) {
        if (y->val == y->next->val) {
            i = y->val;
            while (y && y->val == i) y = y->next;
        } else {
            temp->next = y;
            temp = temp->next;
            y = y->next;
        }
    }

    if (y)
        temp->next = y;
    else
        temp->next = NULL;
    return node->next;
}

void test(struct ListNode* head,struct ListNode* wanted){
    struct ListNode* actual = deleteDuplicates(head);
    //print_list(head);
    //printf("\n");
    //print_list(wanted);
    assert_list_equal(wanted,actual);
}

int main(){
    test(makeList(7,1,2,3,3,4,4,5),//
    makeList(3,1,2,5));
}
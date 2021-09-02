#include <stdio.h>

#include "../lib/bool.h"
#include "../lib/list.h"

struct ListNode* middleList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    // 1 2 3 4 5 6
    //           f
    //       s
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL) {
            fast = fast->next;
        }
    }
    return slow;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newHead = NULL;
    struct ListNode* tmpNode;
    while (head != NULL) {
        tmpNode = head->next;
        head->next = newHead;
        newHead = head;
        head = tmpNode;
    }
    return newHead;
}

// Total: O(2.5n)
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // 1->2->   3   ->2->1
    // 1->2->   3
    //       <- 3    <-2<-1
    // O(1.5n)
    struct ListNode* middle = middleList(head);

    // print_list_msg("head", head);
    // print_list_msg("middle before reverse", middle);
    if (middle) {
        // O(0.5n)
        middle = reverseList(middle);
        // print_list_msg("middle after reverse", middle);
        // print_list_msg("head after reverse middle", head);
    }

    // O(0.5n)
    while (middle != NULL) {
        if (middle->val != head->val) {
            return false;
        }

        middle = middle->next;
        head = head->next;
    }
    return true;
}

void test(struct ListNode* head, bool wanted) {
    bool actual = isPalindrome(head);
    if (actual != wanted) {
        printf("[ERROR] actual=%s, wanted=%s\n", bool2str(actual),
               bool2str(wanted));
    }
}

int main() {
    test(makeList(2, 1, 2), false);
    test(makeList(3, 1, 2, 1), true);
    test(makeList(4, 1, 2, 2, 1), true);
    test(makeList(7, 1, 2, 3, 5, 3, 2, 1), true);
    test(makeList(7, 1, 2, 3, 5, 3, 2, 0), false);
    test(makeList(8, 1, 2, 3, 4, 4, 3, 2, 1), true);
}
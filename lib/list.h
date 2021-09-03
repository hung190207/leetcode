#ifndef __LIST__
#define __LIST__

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* makeList(int n, ...) {
    struct ListNode pre = {};
    struct ListNode* parent = &pre;

    va_list arr;
    va_start(arr, n);

    for (int i = 0; i < n; i++) {
        struct ListNode* cur =
            (struct ListNode*)calloc(1, sizeof(struct ListNode));
        cur->val = va_arg(arr, int);
        parent->next = cur;
        parent = cur;
    }

    va_end(arr);
    return pre.next;
}

void print_list(struct ListNode* head) {
    if (head == NULL) {
        printf("\n");
        return;
    }

    printf("%d", head->val);
    head = head->next;

    while (head != NULL) {
        printf(" -> %d", head->val);
        head = head->next;
    }

    printf("\n");
}

void print_list_msg(char* msg, struct ListNode* head) {
    printf("%s\n", msg);
    print_list(head);
}

bool assert_list_equal(struct ListNode* wanted, struct ListNode* actual) {
    struct ListNode* a = actual;
    struct ListNode* w = wanted;
    while (a != NULL && w != NULL) {
        if (a->val != w->val) {
            printf("[ERROR] wanted val=%d, actual=%d\n", w->val, a->val);
            printf("[ERROR] actual: ");
            print_list(actual);
            printf("[ERROR] wanted: ");
            print_list(wanted);
            return false;
        }
        w = w->next;
        a = a->next;
    }

    if (a != NULL || w != NULL) {
        printf("[ERROR] 2 lists have different size\n");
        printf("[ERROR] actual: ");
        print_list(actual);
        printf("[ERROR] wanted: ");
        print_list(wanted);
        return false;
    }

    return true;
}

//       V
// head: 1 -> 2 -> 3 -> 4
// val: 3
// return: 3->4
struct ListNode* search_list(struct ListNode* head, int val) {
    struct ListNode* node = head;
    while (node != NULL) {
        if (node->val == val) {
            return node;
        }

        node = node->next;
    }

    return node;  // node == NULL
}

#endif
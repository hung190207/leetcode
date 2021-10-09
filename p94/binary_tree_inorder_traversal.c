#include <stdio.h>

#include "../lib/array.h"
#include "../lib/tree.h"

void inorder(struct TreeNode* node, int* a, int* n) {
    if (node != NULL) {
        inorder(node->left, a, n);
        a[(*n)++] = node->val;
        inorder(node->right, a, n);
    }
}

int* inorderTraversal(struct TreeNode* root, int* n) {
    *n = 0;
    int* result = (int*)malloc(sizeof(int) * 100);
    inorder(root, result, n);
    return result;
}

void test(Tree root, Ints wanted) {
    int actual_n;
    int* actual_arr = inorderTraversal(root, &actual_n);

    if (actual_n != wanted.size) {
        error("actual_n=%d, wanted.size=%d", actual_n, wanted.size);
        return;
    }

    compare_array(wanted.values, actual_arr, wanted.size);
}

int main() {
    test(tree_new((Ints){.size = 4, .values = (int[]){1, NA, 2, 3}}),  //
         (Ints){.size = 3, .values = (int[]){1, 3, 2}});

    test(tree_new((Ints){.size = 3, .values = (int[]){1, 2, 3}}),  //
         (Ints){.size = 3, .values = (int[]){2, 1, 3}});
    return 0;
}
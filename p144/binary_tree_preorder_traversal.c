#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preorder(struct TreeNode* root, int* a, int* b) {
    if (root != NULL) {
        a[*b] = root->val;
        (*b)++;
        preorder(root->left, a, b);
        preorder(root->right, a, b);
    }
}

int* preorderTraversal(struct TreeNode* root, int* n) {
    int i[1] = {0};
    int a[1000];
    preorder(root, a, i);
    *n = *i;
    int* result = (int*)malloc(sizeof(int) * (*n));
    for (int j = 0; j < *i; j++) {
        result[j] = a[j];
    }
    return result;
}
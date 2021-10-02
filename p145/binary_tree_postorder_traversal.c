#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void get_size(struct TreeNode* root, int* size) {
    if (!root) {
        return;
    }

    if (root->left) {
        get_size(root->left, size);
    }

    if (root->right) {
        get_size(root->right, size);
    }

    (*size)++;
}

void traversal(struct TreeNode* root, int* arr, int* n) {
    if (!root) {
        return;
    }

    if (root->left) {
        traversal(root->left, arr, n);
    }
    if (root->right) {
        traversal(root->right, arr, n);
    }

    n[(*arr)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* arr) {
    int size = 0;
    int index = 0;
    int* temp = NULL;

    get_size(root, &size);

    temp = (int*)calloc(size, sizeof(int));

    traversal(root, &index, temp);

    *arr = size;
    return temp;
}
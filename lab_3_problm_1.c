#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    inorder(root->left, result, index);
    result[(*index)++] = root->val;
    inorder(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    inorder(root, result, returnSize);
    return result;
}

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}

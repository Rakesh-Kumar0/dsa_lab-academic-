#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL && targetSum == root->val) {
        return 1;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

#define MAX_QUEUE_SIZE 100
struct Queue {
    struct TreeNode* arr[MAX_QUEUE_SIZE];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear < MAX_QUEUE_SIZE) {
        q->arr[q->rear++] = node;
    }
}

struct TreeNode* dequeue(struct Queue* q) {
    if (!isEmpty(q)) {
        return q->arr[q->front++];
    }
    return NULL;
}

struct TreeNode* buildTree() {
    int val;
    printf("Enter root node value: ");
    scanf("%d", &val);
    if (val == -1) return NULL;
    
    struct TreeNode* root = newNode(val);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    
    while (!isEmpty(&q)) {
        struct TreeNode* current = dequeue(&q);
        
        int leftVal, rightVal;
        printf("Enter left child of %d (-1 for NULL): ", current->val);
        scanf("%d", &leftVal);
        if (leftVal != -1) {
            current->left = newNode(leftVal);
            enqueue(&q, current->left);
        }
        
        printf("Enter right child of %d (-1 for NULL): ", current->val);
        scanf("%d", &rightVal);
        if (rightVal != -1) {
            current->right = newNode(rightVal);
            enqueue(&q, current->right);
        }
    }
    return root;
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();
    
    int targetSum;
    printf("Enter target sum: ");
    scanf("%d", &targetSum);
    
    if (hasPathSum(root, targetSum)) {
        printf("True");
    } else {
        printf("False");
    }
    
    return 0;
}

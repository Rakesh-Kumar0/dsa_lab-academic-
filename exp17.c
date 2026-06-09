#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertLevelOrder(int arr[], int i, int n) {
    if (i >= n || arr[i] == -1)
        return NULL;
    
    struct Node* root = createNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);
    return root;
}

int findMaxWidthLevel(struct Node* root) {
    if (root == NULL)
        return -1;

    int maxWidth = 0;
    int maxLevel = 0;
    int level = 0;
    
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        int levelWidth = rear - front;
        if (levelWidth > maxWidth) {
            maxWidth = levelWidth;
            maxLevel = level;
        }
        
        int count = levelWidth;
        while (count--) {
            struct Node* current = queue[front++];
            if (current->left)
                queue[rear++] = current->left;
            if (current->right)
                queue[rear++] = current->right;
        }
        level++;
    }
    return maxLevel;
}

int main() {
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements (use -1 for NULL nodes): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = insertLevelOrder(arr, 0, n);
    printf("Level with maximum nodes: %d\n", findMaxWidthLevel(root));
    return 0;
}

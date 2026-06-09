#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node* data;
    struct Queue* next;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void enqueue(Queue** front, Queue** rear, Node* data) {
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    if (*rear) {
        (*rear)->next = newNode;
    } else {
        *front = newNode;
    }
    *rear = newNode;
}

Node* dequeue(Queue** front, Queue** rear) {
    if (*front == NULL) return NULL;
    Queue* temp = *front;
    Node* node = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return node;
}

Node* buildTree() {
    int data;
    printf("Enter root node value: ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    Node* root = createNode(data);
    Queue* front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);
    
    while (front) {
        Node* current = dequeue(&front, &rear);
        
        printf("Enter left child of %d (-1 for no child): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->left = createNode(data);
            enqueue(&front, &rear, current->left);
        }
        
        printf("Enter right child of %d (-1 for no child): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->right = createNode(data);
            enqueue(&front, &rear, current->right);
        }
    }
    return root;
}

Node* mirrorTree(Node* root) {
    if (root == NULL) return NULL;
    Node* temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);
    return root;
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue* front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);
    
    while (front) {
        Node* current = dequeue(&front, &rear);
        printf("%d ", current->data);
        if (current->left) enqueue(&front, &rear, current->left);
        if (current->right) enqueue(&front, &rear, current->right);
    }
    printf("\n");
}

int main() {
    printf("Constructing original tree...\n");
    Node* root = buildTree();
    
    printf("Original Tree (Level-Order): ");
    levelOrder(root);
    
    root = mirrorTree(root);
    
    printf("Mirrored Tree (Level-Order): ");
    levelOrder(root);
    
    return 0;
}

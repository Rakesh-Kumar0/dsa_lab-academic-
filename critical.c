
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to find and print critical points with explanations
void findCriticalPoints(struct Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        printf("Not enough nodes to have a critical point.\n");
        return;
    }

    struct Node* prev = head;
    struct Node* curr = head->next;
    struct Node* next = curr->next;
    int position = 2; // Since we start from the second node
    int criticalCount = 0;

    printf("\nCritical Points and Explanation:\n");

    while (next != NULL) {
        if (curr->data > prev->data && curr->data > next->data) { 
            // Local Maxima
            printf("Position %d: %d (Local Maximum: %d > %d and %d > %d)\n", 
                    position, curr->data, curr->data, prev->data, curr->data, next->data);
            criticalCount++;
        } else if (curr->data < prev->data && curr->data < next->data) {  
            // Local Minima
            printf("Position %d: %d (Local Minimum: %d < %d and %d < %d)\n", 
                    position, curr->data, curr->data, prev->data, curr->data, next->data);
            criticalCount++;
        }
        prev = curr;
        curr = next;
        next = next->next;
        position++;
    }

    printf("\nTotal Number of Critical Points: %d\n", criticalCount);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to execute the program
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of elements in linked list: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("A linked list must have at least 3 nodes to contain a critical point.\n");
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }

    printf("\nOriginal linked list:\n");
    printList(head);

    findCriticalPoints(head);

    return 0;
}


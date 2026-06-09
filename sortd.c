

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

// Function to sort linked list using Bubble Sort
void sortList(struct Node** head) {
    struct Node* current;
    struct Node* index;
    int temp;

    if (*head == NULL)
        return;

    for (current = *head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

// Function to remove duplicate elements from sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNext;

    if (head == NULL)
        return;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }

    printf("Original linked list:\n");
    printList(head);

    // Step 1: Sort the list
    sortList(&head);
    printf("Sorted linked list:\n");
    printList(head);

    // Step 2: Remove duplicates
    removeDuplicates(head);
    printf("Linked list after removing duplicates:\n");
    printList(head);

    return 0;
}

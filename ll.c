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

void insertBefore(struct Node** head, int key, int newData) {
    struct Node* newNode = createNode(newData);
    
    if (*head == NULL) {
        printf("List is empty. Cannot insert before %d.\n", key);
        free(newNode);
        return;
    }

    if ((*head)->data == key) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Key %d not found in the list.\n", key);
        free(newNode);
    }
}

void append(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    
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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, key, newData;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Original linked list: ");
    printList(head);

    printf("Enter the key before which to insert: ");
    scanf("%d", &key);

    printf("Enter the new data to insert: ");
    scanf("%d", &newData);

    insertBefore(&head, key, newData);
    
    printf("Updated linked list: ");
    printList(head);

    return 0;
}


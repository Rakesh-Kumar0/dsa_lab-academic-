#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* p(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_Begin(struct Node** head_ref, int new_data) {
    struct Node* new_node = p(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, new_data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert_Begin(&head, data);
    }

    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Enter data for the new node to be inserted at the beginning: ");
    scanf("%d", &new_data);
    insert_Begin(&head, new_data);

    printf("Updated Linked List: \n");
    printList(head);

    return 0;
}

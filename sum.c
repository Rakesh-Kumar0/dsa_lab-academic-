#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int digit;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->digit);
        head = head->next;
    }
    printf("NULL\n");
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* result = NULL;
    Node** temp = &result;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->digit;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->digit;
            l2 = l2->next;
        }
        carry = sum / 10;
        *temp = createNode(sum % 10);
        temp = &((*temp)->next);
    }
    return result;
}

Node* readList() {
    Node* head = NULL;
    int n;
    printf("Enter digits (-1 to stop): ");
    while (1) {
        scanf("%d", &n);
        if (n == -1)
            break;
        insertEnd(&head, n);
    }
    return head;
}

int main() {
    printf("Enter first number in reverse order:\n");
    Node* l1 = readList();
    
    printf("Enter second number in reverse order:\n");
    Node* l2 = readList();

    Node* result = addTwoNumbers(l1, l2);

    printf("Sum (in reverse order): ");
    printList(result);

    return 0;
}
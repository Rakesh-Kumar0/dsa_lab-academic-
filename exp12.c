#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}


int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}


int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}


void display(Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    Node* temp = top;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* top = NULL;
    
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);
    
    printf("Top element is %d\n", peek(top));
    
    printf("Popped %d from the stack\n", pop(&top));
    display(top);
    
    printf("Popped %d from the stack\n", pop(&top));
    display(top);
    
    printf("Popped %d from the stack\n", pop(&top));
    display(top);
    
    return 0;
}
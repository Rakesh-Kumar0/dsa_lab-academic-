#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *newnode;

struct node* reverse_k_group(struct node* head, int k) {
    if (head == NULL || k <= 1) {
        return head; 
    }
    int length = 0;
    struct node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    if (k > length) {
        printf("k is greater than the length of the list. No changes made.\n");
        return head;
    }
    struct node *prev = NULL, *current = head, *next = NULL;
    struct node *new_head = NULL, *tail = NULL, *prev_tail = NULL;
    
    while (length >= k) { 
        int count = 0;
        struct node *segment_head = current;
        while (count < k && current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (new_head == NULL) {
            new_head = prev;
        }
        
        if (prev_tail != NULL) {
            prev_tail->next = prev;
        }
        prev_tail = segment_head;
        segment_head->next = current;
        length -= k;
        prev = NULL;
    }

    return new_head;
}

void print_list(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int value;
    printf("Enter the elements of the list (-1 to stop):\n");

    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == -1)
            break;
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Original linked list:\n");
    print_list(head);

    int k;
    printf("Enter the number of nodes to reverse in each group: ");
    scanf("%d", &k);

    head = reverse_k_group(head, k);

    printf("Modified linked list:\n");
    print_list(head);

return 0;
}
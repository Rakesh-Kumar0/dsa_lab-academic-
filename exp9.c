#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head,*newnode,*temp;

void swap_list_adjecent(){
    if(head==NULL||head->next==NULL){
        printf("Head has less element\n");
    }
    struct node dummy;
    dummy.next = head;
    struct node *prev = &dummy, *first, *second;
    while(prev->next!=NULL&&prev->next->next!=NULL){
        first=prev->next;
        second=first->next;
        first->next=second->next;
        second->next=first;
        prev->next=second;
        prev=first;
    }
    head=dummy.next;
}


void print_list(){
    temp =head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}



int main(){
    int value;
    printf("Enter the element of the list (-1 to stop):\n");
    while (1)    {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == -1)
            break;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp->next = newnode;
        }
        temp = newnode;
    }
    printf("Printing the original linked lsit: ");
    print_list();

    swap_list_adjecent();
    printf("Printing the swap list: ");
    print_list();
}
#include<stdio.h>
#include<stdlib.h>

// node structure define
struct node
{
    int data;
    struct node *next;
};


struct node* add_at_big(struct node* head,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
    temp -> next = head;
    head = temp ;

    return head;
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head -> data = 64;
    head -> next = NULL;

    struct node *ptr = malloc(sizeof(struct node));

    head = add_at_big(head,34);
    head = add_at_big(head,23);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr -> next;
    }
    return 0;
}
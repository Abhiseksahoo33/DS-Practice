#include<stdio.h>
#include<stdlib.h>

// node structure define
struct node
{
    int data;
    struct node *next;
};


struct node* add_at_end(struct node* ptr,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
    ptr -> next = temp;

    return temp;
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head -> data = 64;
    head -> next = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr,34);
    ptr = add_at_end(ptr,23);
    ptr = add_at_end(ptr,76);
    ptr = add_at_end(ptr,37);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr -> next;
    }
    return 0;
}
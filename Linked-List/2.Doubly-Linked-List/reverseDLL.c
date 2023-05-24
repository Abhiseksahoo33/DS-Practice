#include<stdio.h>
#include<stdlib.h>

// node structure define
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node * addToEmpty(struct node*head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;
    return head;

}

struct node * addToEnd(struct node*head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    struct node *temp2 = head;
    while (temp2 -> next != NULL)
    {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp;
    temp -> prev = temp2;

    return head;
}

struct node *reverseList(struct node *head)
{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1 -> next;

    ptr1 -> next = NULL;
    ptr1 -> prev = ptr2;
    while (ptr2 != NULL)
    {
        ptr2 -> prev = ptr2 -> next;
        ptr2 -> next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2 -> prev;
    }
    head = ptr1;
    return head;
}

void displayList(struct node* head)
{
    struct node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
    
}

int main()
{
    struct node *head = NULL;
    head = addToEmpty(head, 53);
    head = addToEnd(head, 86);
    head = addToEnd(head, 73);

    printf("Before Reversing  ");
    displayList(head);
    head = reverseList(head);
    printf("After Reversing ");
    displayList(head);
    return 0;
}


/*
Before Reversing  53 -> 86 -> 73 -> 
After Reversing 73 -> 86 -> 53 ->
*/
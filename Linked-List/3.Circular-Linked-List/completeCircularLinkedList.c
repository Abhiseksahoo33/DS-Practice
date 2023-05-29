#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *addToEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
}

struct node *addAtBeg(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    temp -> next = tail -> next;
    tail -> next = temp;
    return tail;
}

struct node *addAtEnd(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    temp -> next = tail -> next;
    tail -> next = temp;
    tail = tail->next;
    return tail;
}

struct node *addAtPos(struct node *tail, int data, int pos)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    
    struct node *p = tail->next;

    while (pos > 1)
    {
        p = p->next;
        pos--;
    }
    if (p == tail)
    {
        tail = addAtEnd(tail,data);
    }
    else
    {
        temp -> next = p -> next;
        p -> next = temp;
    }

    return tail;
}

void print_nodes(struct node* tail)
{
    struct node* p = tail -> next;
    do
    {
        printf("%d ->",p->data);
        p = p->next;
    } while (p != tail->next);
    
}


int main()
{
    int n, first, data;
    struct node *tail;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if (n == 0)
    {
        return 0;
    }
    else
    {
        printf("Enter the element for 1st node: ");
        scanf("%d",&first);
    }
    tail = addToEmpty(first);
    for (int i = 1; i < n; i++)
    {
        printf("Enter %dth element of list: ",i+1);
        scanf("%d",&data);
        tail = addAtEnd(tail,data);
    }
    
    print_nodes(tail);
    return 0;
}
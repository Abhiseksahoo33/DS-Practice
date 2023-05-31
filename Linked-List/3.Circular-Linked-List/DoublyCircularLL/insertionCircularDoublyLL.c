#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addToEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> prev = temp;
    temp -> next = temp;
    return temp;
}

struct node* insertAtBeg(struct node* tail, int data)
{
    //create new node by calling addToEmpty()
    struct node* newp = addToEmpty(data);
    if (tail == NULL)
    {
        return newp;
    }
    
    struct node* temp = tail->next;
    newp->next = temp;
    newp->prev = tail;
    temp->prev = newp;
    tail->next = newp;

    return tail;
}

void print_nodes(struct node* tail)
{
    if (tail == NULL)
    {
        printf("No Element in the List!");
    }
    
    struct node* p = tail -> next;
    do
    {
        printf("%d ->",p->data);
        p = p->next;
    } while (p != tail->next);
    
}

int main()
{
    struct node *tail;
    tail = addToEmpty(36);
    tail = insertAtBeg(tail,75);
    print_nodes(tail);
    return 0;
}
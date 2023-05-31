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

struct node* deleteFirstNode(struct node* tail)
{
    if (tail == NULL)
    {
        return NULL;
    }
    if (tail -> next == tail)
    {
        free(tail);
        tail == NULL;
        return NULL;
    }
    struct node* temp = tail -> next;
    tail -> next = temp -> next;
    free(temp);
    temp = NULL;
    return tail;
    
}

struct node* deleteLastNode(struct node* tail)
{
    if (tail == NULL)
    {
        return NULL;
    }
    if (tail -> next == tail)
    {
        free(tail);
        tail == NULL;
        return NULL;
    }
    struct node* temp = tail -> next;
    
    while (temp -> next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
    
}

struct node* deleteintermediateNode(struct node* tail, int pos)
{
    if (tail == NULL)
    {
        return NULL;
    }
    if (tail -> next == tail)
    {
        free(tail);
        tail == NULL;
        return NULL;
    }
    if (pos == 1)
    {
        tail = deleteFirstNode(tail);
    }
    else
    {
    struct node* temp = tail -> next;
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    struct node* temp2 = temp -> next;
    temp -> next = temp2->next;
    free(temp2);
    temp2 = NULL;
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
    int data = 36;
    struct node *tail;
    tail = addToEmpty(data);
    tail = addAtBeg(tail,46);
    tail = addAtEnd(tail,86);
    tail = addAtBeg(tail,27);
    int position =2;
    tail = addAtPos(tail,99,position);
    printf("Nodes before deletion: "); //Nodes before deletion: 27 ->46 ->99 ->36 ->86
    print_nodes(tail);
    printf("\nNodes after deletion: ");//Nodes after deletion: 46 ->99 ->36 ->86 ->
    tail = deleteFirstNode(tail);
    print_nodes(tail);
    printf("\nDeleting Last Node: "); //Deleting Last Node: 46 ->99 ->36 ->
    tail = deleteLastNode(tail);
    print_nodes(tail);
    printf("\nDeleting intermediate Node: ");
    int positiontodelete = 2;
    tail = deleteintermediateNode(tail,positiontodelete);
    print_nodes(tail);                 //Deleting intermediate Node: 46 ->36 ->
    return 0;
}
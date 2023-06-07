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

struct node* insertAtEnd(struct node* tail, int data)
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
    tail = newp;
    return tail;
}

struct node* insertAtPos(struct node* tail, int data, int pos)
{
    //create new node by calling addToEmpty()
    struct node* newp = addToEmpty(data);
    if (tail == NULL)
    {
        return newp;
    }
    
    struct node* temp = tail->next;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    newp->prev = temp;
    newp->next = temp->next;
    temp->next->prev = newp;
    temp->next = newp;
    if (temp == tail)
    {
        tail = tail->next;
    }
    return tail;
}
struct node *deleteFirstNode(struct node* tail)
{
    struct node* temp = tail->next;
    if (temp == tail)
    {
        free(tail);
        tail = NULL;
    }
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);

    return tail;
}

struct node *deleteLastNode(struct node* tail)
{
    struct node* temp = tail->next;
    if (temp == tail)
    {
        free(tail);
        tail = NULL;
    }
    temp = tail->prev;
    temp->next = tail->next;
    temp->next->prev = temp;
    free(tail);
    tail = temp;
    
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
    printf("\n");
}

int main()
{
    int position = 0;
    struct node *tail = NULL;
    tail = addToEmpty(36);
    tail = insertAtBeg(tail,75);
    tail = insertAtEnd(tail,80);
    tail = insertAtEnd(tail,11);
    printf("Nodes before Deletion: ");
    print_nodes(tail);
    printf("After deleting first Node: ");
    tail = deleteFirstNode(tail);
    print_nodes(tail);
    printf("After deleting Last Node: ");
    tail = deleteLastNode(tail);
    print_nodes(tail);
    return 0;
}
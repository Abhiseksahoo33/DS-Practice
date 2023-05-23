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

struct node * addToBeg(struct node*head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    temp -> next = head;
    head -> prev = temp;
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

struct node * addAfterPos(struct node*head, int data, int pos)
{
    struct node *newp = malloc(sizeof(struct node));
    newp -> prev = NULL;
    newp -> data = data;
    newp -> next = NULL;
    struct node *temp = head;
    struct node *temp2;

    while (pos != 1)
    {
        temp = temp -> next;
        pos--;
    }
    if (temp -> next == NULL)
    {
        temp -> next = newp;
        newp -> prev = temp;
    }
    else
    {
        temp2 = temp -> next;
        temp -> next = newp;
        temp2 -> prev = newp;
        newp -> next = temp2;
        newp -> prev = temp;
    }

    return head;
}

struct node * addBeforePos(struct node*head, int data, int pos)
{
    struct node *newp = malloc(sizeof(struct node));
    newp -> prev = NULL;
    newp -> data = data;
    newp -> next = NULL;
    struct node *temp = head;
    struct node *temp2;

    while (pos > 2)
    {
        temp = temp -> next;
        pos--;
    }
    if (pos == 1)
    {
        head = addToBeg(head, data);
    }
    else
    {
        temp2 = temp -> next;
        temp -> next = newp;
        temp2 -> prev = newp;
        newp -> next = temp2;
        newp -> prev = temp;
    }

    return head;
}

int countNoOfNodes(struct node* head, int count)
{
    if (head == NULL)
    {
        printf("Empty Linked List");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr -> next;
        count++;
    }
    printf("Number of Nodes: %d \n",count);
    return count;
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
    head = addToBeg(head, 23);
    head = addToEnd(head, 86);
    head = addToEnd(head, 73);
    int count = 0, afterPosition;
    int noOfNodes = countNoOfNodes(head,count);

    printf("Enter position after which you want to add node: ");
    scanf("%d",&afterPosition);
    
    if(afterPosition < noOfNodes)
    {
        if(afterPosition < 1)
        {
            head = addToBeg(head, 89);
        }
        else
        {
            head = addAfterPos(head, 89, afterPosition);
        }
    }
    else
    {
        printf("position is greater than total number of nodes, Adding node at end");
        head = addToEnd(head, 89);    
    }
    

    int beforePosition = 5;
    head = addBeforePos(head, 52, beforePosition);

    displayList(head);
    return 0;
}

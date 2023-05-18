#include<stdio.h>
#include<stdlib.h>
void createSingleLL();

// node structure define
struct node
{
    int data;
    struct node *next;
};

void createSingleLL()
{
    //head pointer to the first node
    struct node *head = malloc(sizeof(struct node)); // (struct node*) is optional
    head -> data = 45;
    head -> next = NULL;
    printf("%d -> ",head->data);
    struct node *current = malloc(sizeof(struct node));
    current -> data = 54;
    current -> next = NULL;
    head -> next = current; // link between 1st and 2nd node (head ----> current)
    printf("%d ->",current->data);
    current = malloc(sizeof(struct node));
    current -> data = 62;
    current -> next = NULL;
    head -> next -> next = current; // link between 2nd and 3rd node
    printf("%d",current->data);
}

int main()
{
    createSingleLL();
    return 0;
}


// output
// 45 -> 54 ->62
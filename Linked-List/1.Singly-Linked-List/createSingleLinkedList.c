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
    printf("%d",head->data);
}

int main()
{
    createSingleLL();
    return 0;
}


// output
// 45


/* commands to run the c file
gcc filename - it will generate exe file named a.exe
then run a.exe file */
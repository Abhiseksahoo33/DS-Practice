#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *circularSLL(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> prev = temp;
    temp -> next = temp;
    return temp;
}

int main()
{
    int data = 36;
    struct node *tail;
    tail = circularSLL(data);

    printf("%d",tail -> data);
    return 0;
}
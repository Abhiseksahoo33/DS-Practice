#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *circularSLL(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
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
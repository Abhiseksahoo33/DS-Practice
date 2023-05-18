#include<stdio.h>
#include<stdlib.h>

// node structure define
struct node
{
    int data;
    struct node *next;
};

/* 
    define: This function will create a single Linked-List
    param : head pointer
    return: void
 */

void createSingleLL(struct node *head)
{
    head -> data = 76;
    head -> next = NULL;
    struct node *current = malloc(sizeof(struct node));
    current -> data = 54;
    current -> next = NULL;
    head -> next = current; // link between 1st and 2nd node (head ----> current)
    current = malloc(sizeof(struct node));
    current -> data = 62;
    current -> next = NULL;
    head -> next -> next = current; // link between 2nd and 3rd node
}
/* 
    define: This function will count the number 
            of nodes in the single Linked-List
    param : head pointer
    return: void
 */

void count_of_nodes(struct node* head)
{
    int count = 0;
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
    
}

/* 
    define: This function will traverse the nodes and print 
            the data in the single Linked-List
    param : head pointer
    return: void
 */
void print_data(struct node* head)
{
    if (head == NULL)
    {
        printf("Empty Linked List");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr -> next;
    }
}
int main()
{
    //head pointer to the first node
    struct node *head = malloc(sizeof(struct node));
    createSingleLL(head);
    count_of_nodes(head);
    print_data(head);
    return 0;
}


/* output
76 -> 54 ->62
Number of Nodes: 3
*/
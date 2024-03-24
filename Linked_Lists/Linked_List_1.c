#include <stdio.h>
#include <stdlib.h>
    
typedef struct node
{
    int data;
    struct node *link;
}
node;

int main(void)
{

    // Inserting a node at the end of a linked list
    node *a;
    a = NULL;
    node *temp = (node *)malloc(sizeof(node));
    (*temp).data = 2; // or temp -> data = 2
    (*temp).link = NULL; // or temp -> link = NULL
    a = temp;
    node *temp2 = (node *)malloc(sizeof(node));
    temp2 -> data = 4;
    temp2 -> link = NULL;

    temp -> link = temp2;

    // a is the address to head node and should never be modified
    node *temp1 = a;

    // Traversing (Logic to reach end of the list)
    while (temp1 != NULL)
        temp1 = temp1 -> link;

    // Printing elements
    temp1 = a;
    while (temp1 != NULL)
    {
        printf("%d ", temp1 -> data);
        temp1 = temp1 -> link;
    }
}
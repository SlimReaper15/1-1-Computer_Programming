#include <stdio.h>
#include <stdlib.h>

void insert(int data, int n);
void Print(void);

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

struct Node *head;

int main(void)
{
    head = NULL; // List is empty
    insert(2, 1); // List: 2
    insert(3, 2); // List: 2, 3
    insert(4, 1); // List: 4, 2, 3
    insert(5, 2); // List: 4, 5, 2, 3
    Print();
}

void insert(int data, int n)
{
    Node *temp1 = (Node *)malloc(sizeof(Node));
    temp1 -> data = data;
    temp1 -> next = NULL;
    if (n == 1)
    {
        temp1 -> next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
        temp2 = temp2 -> next;
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void Print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
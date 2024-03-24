#include <stdio.h>
#include <stdlib.h>

void Insert(int x);
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
    head = NULL; // Empty list
    printf("How many numbers?\n");
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number:\n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
}

void Insert (int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp -> data = x; // or (*temp).data = x
    temp -> next = head;
    head = temp;
}

void Print()
{
    Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
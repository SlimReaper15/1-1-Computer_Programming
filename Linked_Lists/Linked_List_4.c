#include <stdio.h>
#include <stdlib.h>

void Delete(int pos);
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
    int y;
    printf("Enter a position for deletion:\n");
    scanf("%d", &y);
    Delete(y);
    Print();
}

void Delete(int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        head = head -> next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos - 2; i++)
        temp = temp -> next;
    Node *temp1 = temp -> next;
    temp -> next = temp1 -> next;
    free(temp1);
}

void Insert(int x)
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
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int a;
    struct Node *next;
} Node;

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp -> next != NULL)
    {
        Node *after = temp -> next;
        if (after -> a == temp -> a)
        {
            temp -> next = after -> next;
            free(after);
        }
        else
            temp = temp -> next;
    }
    return head;
}

int main(void)
{
    printf("Enter the number of colors in the list: ");
    int n;
    scanf("%d", &n);

    Node *head = NULL;

    printf("Enter the colors: ");

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        Node *now = (Node *)malloc(sizeof(Node));
        now -> a = x;
        now -> next = NULL;

        if (head == NULL)
            head = now;
        else
        {
            Node *temp = head;
            while (temp -> next != NULL)
                temp = temp -> next;
            temp -> next = now;
        }
    }

    removeDuplicates(head);

    printf("Modified Linked List: ");
    
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp -> next == NULL)
        {
            printf("%d\n", temp -> a);
            break;
        }
        printf("%d -> ", temp -> a);
        temp = temp -> next;
    }
}
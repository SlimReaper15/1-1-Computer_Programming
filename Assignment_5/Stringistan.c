#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char c;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void rev(void)
{
    if (head -> next == NULL)
        return; // No need to reverse 1 character strings
    Node *prev = head;
    Node *current = head -> next;
    Node *after = current -> next;
    prev -> next = NULL;
    while (current != NULL)
    {
        current -> next = prev;
        prev = current;
        current = after;
        if (after != NULL)
            after = after -> next;
    }
    head = prev; // prev is the last element now
}

void start(char j)
{
    Node *newchar = (Node *)malloc(sizeof(Node));
    newchar -> c = j;
    newchar -> next = head;
    head = newchar;

    if (tail == NULL)
        tail = newchar;// Update tail when the list is empty
}

void end(char j)
{
    Node *newchar = (Node *)malloc(sizeof(Node));
    newchar -> c = j;
    newchar -> next = NULL;
    
    if (head == NULL)
    {
        head = newchar;
        tail = newchar;
    }
    else
    {
        tail -> next = newchar;
        tail = newchar;
    }
}

int main(void)
{
    // Inputing the string into a linked list

    char ch;
    while ((ch = getchar()) != '\n')
    {
        Node *newchar = (Node *)malloc(sizeof(Node));
        newchar -> c = ch;
        newchar -> next = NULL;
        if (head == NULL)
        {
            head = newchar;
            tail = newchar; // Keep track of tail so that we can directly insert a new element at the end of the linked list
            continue;
        }
        tail -> next = newchar;
        tail = newchar;
    }

    int m;
    scanf("%d", &m);

    // Calling the required operations
    int track = 0;
    for (int i = 0; i < m; i++)
    {
        int q;
        scanf("%d", &q);
        if (q == 1)
            track++;
        else // q == 2
        {
            int l;
            char j;
            scanf("%d %c", &l, &j);
            if (track % 2 == 0)
            {
                if (l == 1)
                    start(j);
                else // l == 2
                    end(j);
            }
            else
            {
                if (l == 1)
                    end(j);
                else // l == 2
                    start(j);
            }
        }
    }

    // Printing the linked list
    if (track % 2 == 1)
        rev();
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%c", temp -> c);
        temp = temp -> next;
    }
    printf("\n");
}
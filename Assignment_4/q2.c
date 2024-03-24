#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    float a;
    struct Node *next;
} Node;

typedef struct Complex
{
    int n;
    Node *c1;
    Node *c2;
} Complex;

Complex complex;

Node *add()
{
    Node *res = NULL;

    Node *temp1 = complex.c1;
    Node *temp2 = complex.c2;
    while (temp1 != NULL)
    {
        Node *now = (Node *)malloc(sizeof(Node));
        now -> a = temp1 -> a + temp2 -> a;
        now -> next = NULL;

        if (res == NULL)
            res = now;
        else
        {
            Node *temp =  res;
            while (temp -> next != NULL)
                temp = temp -> next;
            temp -> next = now;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return res;
}

Node *subtract()
{
    Node *res = NULL;

    Node *temp1 = complex.c1;
    Node *temp2 = complex.c2;
    while (temp1 != NULL)
    {
        Node *now = (Node *)malloc(sizeof(Node));
        now -> a = temp1 -> a - temp2 -> a;
        now -> next = NULL;

        if (res == NULL)
            res = now;
        else
        {
            Node *temp =  res;
            while (temp -> next != NULL)
                temp = temp -> next;
            temp -> next = now;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return res;
}

float dot()
{
    Node *res = NULL;

    Node *temp1 = complex.c1;
    Node *temp2 = complex.c2;
    float sum = 0;
    while (temp1 != NULL)
    {
        sum += (temp1 -> a * temp2 -> a);
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return sum;
}

float mod(Node *comp)
{
    float sum = 0;
    Node *temp = comp;
    while (temp != NULL)
    {
        float square = temp -> a * temp -> a;
        sum += square;
        temp = temp -> next;
    }
    sum = sqrt(sum);
    return sum;
}

float cosine()
{
    float temp = dot(); // Cosine uses the result of dot
    float ans = temp / (mod(complex.c1) * mod(complex.c2));
    return ans;
}

void print(Node *res)
{
    Node *temp = res;
    while (temp != NULL)
    {
        printf("%.2f ", temp -> a);
            temp = temp -> next;
    }
    printf("\n");
}

int main(void)
{
    char s[10];
    while (1)
    {
        scanf("%s", s);
        if (strcmp(s, "-1") == 0)
            break;
            
        complex.c1 = NULL;
        complex.c2 = NULL;

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            float x;
            scanf("%f", &x);

            Node *now = (Node *)malloc(sizeof(Node));
            now -> a = x;
            now -> next = NULL;

            if (complex.c1 == NULL)
                complex.c1 = now;
            else
            {
                Node *temp = complex.c1;
                while (temp -> next != NULL)
                    temp = temp -> next;
                temp -> next = now;
            }
        } // Filling in c1

        for (int i = 0; i < n; i++)
        {
            float x;
            scanf("%f", &x);

            Node *now = (Node *)malloc(sizeof(Node));
            now -> a = x;
            now -> next = NULL;

            if (complex.c2 == NULL)
                complex.c2 = now;
            else
            {
                Node *temp = complex.c2;
                while (temp -> next != NULL)
                    temp = temp -> next;
                temp -> next = now;
            }
        } // Filling in c2

        Node *res = (Node *)malloc(sizeof(Node));

            
        printf("Result: ");

        if (strcmp(s, "ADD") == 0)
        {
            res = add();
            print(res);
        }

        else if (strcmp(s, "SUB") == 0)
        {
            res = subtract();
            print(res);
        }

        else if (strcmp(s, "COSINE") == 0)
        {
            float ans = cosine();
            printf("%.2f\n", ans);
        }

        else if (strcmp(s, "DOT") == 0)
        {
            float ans = dot();
            printf("%.2f\n", ans);
        }
    }
}

// Don't use global variables
// Use double instead of float
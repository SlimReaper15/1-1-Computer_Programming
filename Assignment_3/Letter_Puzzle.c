#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;
 
int compare(const void *x, const void *y);
int fact(int n);
void permute(char *a, int l, int r, int *counter);
void swap(char *x, char *y);

char **store;

int main(void) 
{ 
    char s[9];
    scanf("%s", s);
    int l = strlen(s);
    int total = fact(l);
    store = (char **)malloc(total * sizeof(char *));
    for (int i = 0; i < total; i++)
        store[i] = (char *)malloc(9 * sizeof(char));
    int counter = 0;
    permute(s, 0, l - 1, &counter);
    qsort(store, total, sizeof(string), compare);
    int count = 0;
    for (int i = 0; i < total; i++)
    {
        count++;
        while (i < total - 1 && strcmp(store[i + 1], store[i]) == 0)
            i++;
    }
    printf("%d\n", count);
    for (int i = 0; i < total; i++)
    {
        printf("%s\n", store[i]);
        while (i < total - 1 && strcmp(store[i + 1], store[i]) == 0)
            i++;
    }
}

int compare(const void *x, const void *y)
{
    string s1 = *(string *)x;
    string s2 = *(string *)y;
    return strcmp(s1, s2);
}

int fact(int n)
{
    int prod = 1;
    for (int i = n; i > 1; i--)
        prod *= i;
    return prod;
}
  
void permute(char *a, int l, int r, int *counter) 
{ 
    int i;
    int x = *counter;
    if (l == r) 
    {
        strcpy(store[x], a);
        (*counter)++;
    }
    else
    { 
        for (i = l; i <= r; i++) 
        { 
            swap((a + l), (a + i)); 
            permute(a, l + 1, r, counter);
            swap((a + l), (a + i)); 
        } 
    } 
}

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}
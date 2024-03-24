#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void smallchar(void);
void bigchar(void);
char *workalready(void);
char *workalready1(void);

char *s;
char *ss;
int l;
int *store;
int *store1;
int count = 0, count1 = 0;
int indice = 0, indice1 = 0;

int main(void)
{
    s = (char *)malloc(2002 * sizeof(char));
    ss = (char *)malloc(2002 * sizeof(char));
    store = (int *)malloc(1000 * sizeof(int));
    store1 = (int *)malloc(1000 * sizeof(int));
    scanf("%s", s);
    l = strlen(s);
    strncat(s, s, l);
    strcpy(ss, s);

    smallchar();
    bigchar();

    char *out = workalready();
    out[l] = '\0';
    printf("%s\n", out);

    char *out1 = workalready1();
    out1[l] = '\0';
    printf("%s\n", out1);
}

void smallchar(void)
{
    int min = 0;
    for (int i = 1; i < l; i++)
    {
        if (s[i] < s[min])
            min = i;
    }
    for (int i = 0; i < l; i++)
    {
        if (s[i] == s[min])
        {
            store[count] = i;
            count++;
        }
    }
}

// store contains the indices of all the smallest characters of the string
// count contains the number of such characters

void bigchar(void)
{
    int max = 0;
    for (int i = 1; i < l; i++)
    {
        if (s[i] > s[max])
            max = i;
    }
    for (int i = 0; i < l; i++)
    {
        if (s[i] == s[max])
        {
            store1[count1] = i;
            count1++;
        }
    }
}

char *workalready(void)
{
    char *next[count];
    for (int i = 0; i < count; i++)
        next[i] = &s[store[i]];
    char *temp = next[0];
    for (int i = 1; i < count; i++)
    {
        if (strcmp(next[i], temp) < 0)
        {
            temp = next[i];
            indice = i;
        }
    }
    return temp;
}

char *workalready1(void)
{
    char *next[count1];
    for (int i = 0; i < count1; i++)
        next[i] = &ss[store1[i]];
    char *temp = next[0];
    for (int i = 1; i < count1; i++)
    {
        if (strcmp(next[i], temp) > 0)
        {
            temp = next[i];
            indice1 = i;
        }
    }
    return temp;
}
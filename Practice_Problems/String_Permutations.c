#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *s, int l, int r)
{
    if (l == r)
        printf("%s\n", s);
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s + l, s + i);
            permute(s, l + 1, r);
            swap(s + l, s + i);
        }
    }
}

int main(void)
{
    char s[4] = "ABC";
    int n = strlen(s);
    permute(s, 0, n - 1);
}
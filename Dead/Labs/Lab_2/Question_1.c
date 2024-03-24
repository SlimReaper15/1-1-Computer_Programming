#include <stdio.h>
int main(void)
{
    int n, sum = 0;
    char c;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &c);
        sum += c - 48;
    }
    if (sum % 3 == 0)
        printf("YES\n");
    else
        printf("NO\n");
}
#include <stdio.h>
int main(void)
{
    int n, a, temp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        temp ^= a;
    }
    printf("%d\n", temp);
}
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, min = (1e5) + 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        int x = abs(a);
        if (x < min)
            min = x;
    }
    printf("%d\n", min);
}
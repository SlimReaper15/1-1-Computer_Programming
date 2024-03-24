#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int level[n];
    for (int i = 0; i < n; i++)
        level[i] = 0;
    for (int i = 0; i < 2; i++)
    {
        int a;
        scanf("%d", &a);
        for (int j = 0; j < a; j++)
        {
            int lev;
            scanf("%d", &lev);
            level[lev - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (level[i] == 0)
        {
            printf("Oh, my keyboard!\n");
            return 0;
        }
    }
    printf("I become the guy.\n");
}
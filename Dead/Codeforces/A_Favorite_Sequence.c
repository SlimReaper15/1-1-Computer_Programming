#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);
        int track = 0;
        for (int j = 0; j < n; j++)
        {
            if (j % 2 == 0)
                printf("%d ", a[track]);
            else
            {
                printf("%d ", a[n - 1 - track]);
                track++;
            }
        }
        printf("\n");
    }
}
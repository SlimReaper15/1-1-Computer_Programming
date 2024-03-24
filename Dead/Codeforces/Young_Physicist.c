#include <stdio.h>
int main(void)
{
    int n, v[3];
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
        v[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int a[3];
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[j]);
            v[j] += a[j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (v[i] != 0)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
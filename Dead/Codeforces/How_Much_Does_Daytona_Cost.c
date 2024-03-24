#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[n];
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);
        int flag;
        for (int j = 0; j < n; j++)
        {
            flag = 0;
            if (a[j] == k)
            {
                printf("YES\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("NO\n");
    }
}
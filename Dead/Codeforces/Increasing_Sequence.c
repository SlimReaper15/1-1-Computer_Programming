#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int ans = 1;
        for (int j = 0; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            if (ans == a)
                ans += 2;
            else
                ans++;
        }
        printf("%d\n", ans - 1);
    }
}
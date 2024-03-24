#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int ans = 1;
    int x = 1e9 + 7;
    for (int i = 0; i < n; i++)
        ans = (ans * 2) % x;
    printf("%d\n", ans);
}
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    long long int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        scanf("%d", &a);
        sum += a;
    }
    printf("%d", (n * (n + 1LL) / 2LL) - sum);
}
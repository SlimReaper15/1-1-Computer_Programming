#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    long long int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] < 0)
        {
            count += (a[i] - a[i + 1]);
            a[i + 1] = a[i];
        }
    }
    printf("%lld\n", count);
}
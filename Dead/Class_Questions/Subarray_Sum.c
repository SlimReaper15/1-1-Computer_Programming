#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int k;
    scanf("%d", &k);
    int sum = 0, l = 0, r = 0;
    while (r < n)
    {
        sum += a[r];
        r++;
        while (l < r && sum > k)
        {
            sum -= a[l];
            l++;
        }
        if (sum == k)
        {
            for (int i = l; i < r; i++)
                printf("%d ", a[i]);
            printf("\n");
        }
    }
}
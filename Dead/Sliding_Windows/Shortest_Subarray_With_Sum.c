#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n], x;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    int sum = 0, l = 0, r = 0, min = n + 1;
    while (r < n)
    {
        sum += a[r];
        r++;
        while (l < r && sum >= x) // sum = x --> two wrongs make a right
        {
            sum -= a[l];
            l++;
            if (r - l + 1 < min)
                min = r - l + 1;
        }
    }
    printf("%d\n", min);
}
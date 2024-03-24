#include <math.h>
#include <stdio.h>
int main(void)
{
    int n, s;
    scanf("%d %d", &n, &s);
    if (n % 2 == 1)
        printf("%d\n", s / ceil(n / 2.0));
    else
    {
        int k = (n / 2) + 1;
        if (s % k == k - 1)
            printf("%g\n", (s / k) + 0.5);
        else
            printf("%d\n", s / k);
    }
}

/* (n / 2) + 1 = k
 * 10, 18 - 23
 * 0 0 0 0 3 3 3 3 3 3 (s % k == 0)
 *         3 3 3 3 3 4
 *         3 3 3 3 4 4
 *         3 3 3 4 4 4
 *         3 3 4 4 4 4 
 *         3 4 4 4 4 4 (s % k == k - 1) */
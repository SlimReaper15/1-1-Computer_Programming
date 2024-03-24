#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);

    /* S = n (n + 1) / 2
     * Should be divisible by 2
     * Either n or n + 1 should be divisible by 4 (since the other number will be odd) */

    if (n % 4 == 1 || n % 4 == 2)
        printf("NO\n");
    else if (n % 4 == 0)
    {
        printf("YES\n%d\n", n / 2);
        for (int i = 1; i < (n / 2); i += 2)
            printf("%d ", i);
        for (int i = (n / 2) + 2; i <= n; i += 2)
            printf("%d ", i);
        
        printf("\n%d\n", n / 2);
        for (int i = 2; i <= (n / 2); i += 2)
            printf("%d ", i);
        for (int i = (n / 2) + 1; i < n; i += 2)
            printf("%d ", i);
    }
    else
    {
        printf("YES\n%d\n%d %d ", ((n - 3) / 2) + 2, 1, 2);
        for (int i = 4; i < 4 + ((n - 3) / 2); i += 2)
            printf("%d ", i);
        for (int i = 4 + ((n - 3) / 2) + 1; i <= 4 + (n - 3); i += 2)
            printf("%d ", i);

        printf("\n%d\n%d ", ((n - 3) / 2) + 1, 3);
        for (int i = 5; i <= 3 + ((n - 3) / 2); i += 2)
            printf("%d ", i);
        for (int i = 3 + ((n - 3) / 2) + 1; i < 3 + (n - 3); i += 2)
            printf("%d ", i);
    }
    printf("\n");
}
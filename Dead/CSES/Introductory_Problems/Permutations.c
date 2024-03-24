#include <math.h>
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("1\n");
    else if (n == 2 || n == 3)
        printf("NO SOLUTION\n");
    else
    {
        int even = n / 2;
        for (int i = 1; i <= even; i++)
            printf("%d ", 2 * i);
        int odd = (int)ceil(n / 2.0);
        for (int i = 1; i <= odd; i++)
            printf("%d ", (2 * i) - 1);
    }
}
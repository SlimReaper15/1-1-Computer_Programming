#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[n], count = 0, prod = 1;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
            if (a[j] == 0)
                count++;
            else
                prod *= a[j];
        }
        if (count == 1)
            printf("%d\n", prod);
        else if (count > 1)
            printf("0\n");
        else
        {
            int copy = prod, max = prod;
            for (int j = 0; j < n; j++)
            {
                prod /= a[j];
                prod *= (a[j] + 1);
                if (prod > max)
                    max = prod;
                prod = copy;
            }
            printf("%d\n", max);
        }
    }
}
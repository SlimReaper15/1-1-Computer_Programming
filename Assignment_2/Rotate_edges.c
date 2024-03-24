#include <stdio.h>
int main(void)
{
    int n, d;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    scanf("%d", &d);
    if (d == 1)
    {
        int c = a[0][n - 1];
        for (int j = n - 1; j > 0; j--)
            a[0][j] = a[0][j - 1];
        for (int i = 0; i < n - 1; i++)
            a[i][0] = a[i + 1][0];
        for (int j = 0; j < n - 1; j++)
            a[n - 1][j] = a[n - 1][j + 1];
        for (int i = n - 1; i > 1; i--)
            a[i][n - 1] = a[i - 1][n - 1];
        a[1][n - 1] = c;
    }
    else
    {
        int c = a[0][0];
        for (int j = 0; j < n - 1; j++)
            a[0][j] = a[0][j + 1];
        for (int i = 0; i < n - 1; i++)
            a[i][n - 1] = a[i + 1][n - 1];
        for (int j = n - 1; j > 0; j--)
            a[n - 1][j] = a[n - 1][j - 1];
        for (int i = n - 1; i > 1; i--)
            a[i][0] = a[i - 1][0];
        a[1][0] = c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == (n - 1))
                printf("%d\n", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
    }
}
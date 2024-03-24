#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n], d[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    int x[101][101] = {0}, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j < b[i]; j++)
        {
            for (int k = c[i]; k < d[i]; k++)
                x[j][k] = 1;
        }
    }
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (x[i][j] == 1)
                count++;
        }
    }
    printf("%d\n", count);
}
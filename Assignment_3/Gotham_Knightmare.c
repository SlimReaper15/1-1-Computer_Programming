#include <stdio.h>
long long int firebolt (int i, int n, int m, int k, int x[], int y[], long long int mem[][m]);

long long int aa = 1e9 + 7;
int main(void)
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int x[k], y[k];
    long long int mem[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            mem[i][j] = 0;
    }
    for (int i = 0; i < k; i++)
        scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < k; i++)
        mem[x[i] - 1][y[i] - 1] = -1;
    for (int i = 0; i < m; i++)
        printf("%lld ", (firebolt(i, n, m, k, x, y, mem)) % aa);
    printf("\n");
}

long long int firebolt (int i, int n, int m, int k, int x[], int y[], long long int mem[][m])
{
    // i = Column index, n = No. of rows, m = No. of Columns
    // k = No. of forbidden squares, (x[0], y[0] = Coordinates of first forbidden square
    if (i < 0 || i > m - 1)
        return 0;
    if (mem[n - 1][i] == -1)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
    {
        if (i - 2 < 0 && i + 2 > m - 1)
            return 0;
        else if (i == 0 || i == 1 || i == m - 2 || i == m - 1)
            return 1;
        else
            return 2;
    }
    else
    {
        if (mem[n - 1][i] != 0)
            return mem[n - 1][i] % aa;
        if (i == 0)
            mem[n - 1][i] = (firebolt(i + 1, n - 2, m, k, x, y, mem) % aa + firebolt(i + 2, n - 1, m, k, x, y, mem) % aa) % aa;
        else if (i == 1)
            mem[n - 1][i] = (firebolt(i - 1, n - 2, m, k, x, y, mem) % aa + firebolt(i + 1, n - 2, m, k, x, y, mem) % aa + firebolt(i + 2, n - 1, m, k, x, y, mem) % aa) % aa;
        else if (i == m - 2)
            mem[n - 1][i] = (firebolt(i - 2, n - 1, m, k, x, y, mem) % aa + firebolt(i - 1, n - 2, m, k, x, y, mem) % aa + firebolt(i + 1, n - 2, m, k, x, y, mem) % aa) % aa;
        else if (i == m - 1)
            mem[n - 1][i] = (firebolt(i - 1, n - 2, m, k, x, y, mem) % aa + firebolt(i - 2, n - 1, m, k, x, y, mem) % aa) % aa;
        else
            mem[n - 1][i] = (firebolt(i - 2, n - 1, m, k, x, y, mem) % aa + firebolt(i - 1, n - 2, m, k, x, y, mem) % aa + firebolt(i + 1, n - 2, m, k, x, y, mem) % aa + firebolt(i + 2, n - 1, m, k, x, y, mem) % aa);
        return mem[n - 1][i] % aa;
    }
}
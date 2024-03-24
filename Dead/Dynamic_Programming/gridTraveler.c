#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;

ll **memo;

ll gridTravel(int i, int j)
{
    if (i == 1 && j == 1)
        return 1;
    else if (i == 0 || j == 0)
        return 0;
    else if (memo[i][j] != -1)
        return memo[i][j];
    // Can return memo[j][i] if it exists and is not 0 since it's basically the same grid but flipped
    // But would require more space in malloc (Need to make sure that mem[j][i] is defined)
    else
    {
        memo[i][j] = gridTravel(i - 1, j) + gridTravel(i, j - 1);
        return memo[i][j];
    }
}

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    // m + 1, n + 1 because we don't use a cell with row or column index 0 to avoid confusion
    memo = (ll **)malloc((m + 1) * sizeof(ll *));
    for (int i = 0; i < m + 1; i++)
    {
        memo[i] = (ll *)malloc((n + 1) * sizeof(ll));
        memset(memo[i], -1, (n + 1) * sizeof(ll));
    }
    printf("%lld\n", gridTravel(m, n));
}
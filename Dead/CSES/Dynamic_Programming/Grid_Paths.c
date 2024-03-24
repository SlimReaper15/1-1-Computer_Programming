#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rem = 1e9 + 7;
int n;
char **grid;
int **memo;

int paths(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;
    else if (grid[n - i][n - j] == '*')
        return 0;
    else if (i == 1 && j == 1)
        return 1;
    else if (memo[i][j] != -1)
        return memo[i][j];
    else
    {
        memo[i][j] = (paths(i - 1, j) % rem + paths(i, j - 1) % rem) % rem;
        return memo[i][j];
    }
}

int main(void)
{
    scanf("%d", &n);
    grid = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
        grid[i] = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf(" %c", &grid[i][j]);
    }
    memo = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = (int *)malloc((n + 1) * sizeof(int));
        memset(memo[i], -1, (n + 1) * sizeof(int));
    }
    printf("%d\n", paths(n, n));
}
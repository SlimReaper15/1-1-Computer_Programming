#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int *c;
int *memo;

int coins(int x)
{
    if (x == 0)
        return 0;
    else if (x < 0)
        return -1;
    else if (memo[x] != 0)
        return memo[x];
    /* The coins function returns -1 if it's not possible to achieve a certain sum
     * Otherwise it returns the minumum number of coins needed
     * For example, (3 6) (2 4 5)
     * 6 branches out to 4, 2, 1
     * 4, if it has a value, contains the min. no of coins required to achieve it
     * If it has -1, it cannot be achieved */
    int mincoins = x + 1;
    for (int i = 0; i < n; i++)
    {
        int node = x - c[i];
        if (coins(node) != -1 && coins(node) + 1 < mincoins)
            mincoins = coins(node) + 1;
    }
    if (mincoins != x + 1)
    {
        memo[x] = mincoins;
        return memo[x];
    }
    else
    {
        memo[x] = -1;
        return memo[x];
    }
}

int main(void)
{
    int x;
    scanf("%d %d", &n, &x);
    c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    memo = (int *)malloc((x + 1) * sizeof(int));
    memset(memo, 0, (x + 1) * sizeof(int));
    printf("%d\n", coins(x));
}
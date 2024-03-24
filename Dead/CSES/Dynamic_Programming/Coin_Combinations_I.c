#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rem = 1e9 + 7;
int n;
int *c;
int *memo;

int coins(int x)
{
    if (x == 0)
        return 1;
    else if (x < 0)
        return 0;
    else if (memo[x] != -1)
        return memo[x];
    // coins(x) returns the number of ways of reaching x
    long long int count = 0;
    for (int i = 0; i < n; i++)
    {
        int node = x - c[i];
        count += coins(node);
        // If 6 branches into 1, 2, 4, no. of ways of achieving 6 is the sum of achieving 1, 2, and 4
    }
    memo[x] = count % rem;
    return memo[x];
}
int main(void)
{
    int x;
    scanf("%d %d", &n, &x);
    c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    memo = (int *)malloc((x + 1) * sizeof(int));
    memset(memo, -1, (x + 1) * sizeof(int));
    printf("%d\n", coins(x));
}
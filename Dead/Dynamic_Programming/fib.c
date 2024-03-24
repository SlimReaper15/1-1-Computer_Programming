#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;

ll *memo;

ll fib(int i)
{
    if (i <= 2)
        return 1;
    else if (memo[i] != 0)
        return memo[i];
    else
    {
        memo[i] = fib(i - 1) + fib(i - 2);
        return memo[i];
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    // n + 1 since we don't use memo[0] to avoid confusion
    memo = (ll *)malloc((n + 1) * sizeof(ll));
    memset(memo, 0, (n + 1) * sizeof(ll));
    printf("%lld\n", fib(n));
}
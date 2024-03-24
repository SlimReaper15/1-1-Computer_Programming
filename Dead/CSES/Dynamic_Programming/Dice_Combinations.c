#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int rem = 1e9 + 7;
int *memo;
 
// We need dice to return the no. of possible ways to get n
 
int dice(int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else if (memo[n] != -1)
        return memo[n];
    long long int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        int x = n - i;
        count += dice(x);
    }
    memo[n] = count % rem;
    return memo[n];
}
 
int main(void)
{
    int n;
    scanf("%d", &n);
    memo = (int *)malloc((n + 1) * sizeof(int));
    memset(memo, -1, (n + 1) * sizeof(int));
    printf("%d\n", dice(n));
}
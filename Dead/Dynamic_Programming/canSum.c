#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *numbers;
int *memo;

int canSum(int n, int l)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return -1;
    else if (memo[n] != 0)
        return memo[n];
    for (int i = 0; i < l; i++)
    {
        int x = n - numbers[i];
        if (canSum(x, l) == 1)
        {
            memo[n] = 1;
            return 1;
        }
    }
    memo[n] = -1;
    return -1;
}

int main(void)
{
    int target, l;
    scanf("%d %d", &target, &l);
    numbers = (int *)malloc(l * sizeof(int));
    for (int i = 0; i < l; i++)
        scanf("%d", numbers + i);
    memo = (int *)malloc((target + 1) * sizeof(int));
    memset(memo, 0, (target + 1) * sizeof(int));
    (canSum(target, l) == 1) ? printf("Yes\n") : printf("No\n");
}
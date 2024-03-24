#include <math.h>
#include <stdio.h>
int main(void)
{
    int n, i = 1;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    int digits = 1 + (floor)(log2(n));
    while (i <= digits)
    {
        int temp = n >> (digits - i);
        printf("%d", temp % 2);
        i++;
    }
    printf("\n");
}
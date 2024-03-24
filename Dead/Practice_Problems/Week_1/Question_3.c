#include <stdio.h>
int main(void)
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = n; i > 0; i /= 10)
        sum = sum * 10 + (i % 10);
    printf("%04d\n", sum);
}
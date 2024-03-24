#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d %d %d\n", (n / 4) % 2, (n / 2) % 2, n % 2);
}
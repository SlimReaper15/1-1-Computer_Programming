#include <stdio.h>
int main(void)
{
    long n;
    scanf("%ld", &n);
    printf("%ld ", n);
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = (n * 3) + 1;
        printf("%ld ", n);
    }
    printf("\n");
}
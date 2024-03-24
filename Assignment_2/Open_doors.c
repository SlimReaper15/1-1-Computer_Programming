#include <math.h>
#include <stdio.h>
int main(void)
{
    long long int n;
    scanf("%lld", &n);
    long long int l = (long long int)(sqrt(n));
    for (long long int i = 1; i <= l; i++)
        printf("%lld ", i * i);
    printf("\n");
}
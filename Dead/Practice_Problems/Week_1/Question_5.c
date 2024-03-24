#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    /* GCD * LCM = Product of two numbers
     * a * b / GCD * GCD <= 3
     * Maximum possible GCD is the lower of the two numbers
     * If b = 3a, maximum possible GCD is a
     * Expression = 3a^2 / a^2 = 3
     * If b > 3a, the expression will be greater than 3 (>3a^2 / a), which does not satisfy the condition
     * Since a and b are integers, b = a, b = 2a, or b = 3a
     * (a, b) --> (b, a) too
    */
    printf("%d\n", n + 2 * (n / 2) + 2 * (n / 3));
}
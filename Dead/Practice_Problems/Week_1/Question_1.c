#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", (10 - n) * (9 - n) * 3); // (10 - n)C2 * 4!/2!2! 
}
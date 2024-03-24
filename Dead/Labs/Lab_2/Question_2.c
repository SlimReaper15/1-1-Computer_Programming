#include <stdio.h>
int main(void)
{
    int x, y, k; // x = 10110, y = 01101, k = 3
    scanf("%d %d %d", &x, &y, &k);
    x >>= k; // x = 00010
    x <<= k; // x = 10000
    int temp = y;
    temp >>= k; 
    temp <<= k; // temp = 01000
    y -= temp; // y = 00101
    printf("%d\n", x + y);
}
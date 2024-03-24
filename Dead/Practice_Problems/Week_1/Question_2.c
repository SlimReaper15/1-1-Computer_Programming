#include <stdio.h>
int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y); // x = 10100001 // y = 11111001
    printf("%d\n", y - x); //      01011000
}
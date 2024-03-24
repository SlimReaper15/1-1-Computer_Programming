#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        float avg = fabs((a - b) / 2.0);
        printf("%d\n", (int)ceil(avg / c));
    }
}